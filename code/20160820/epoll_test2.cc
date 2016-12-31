#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/wait.h>

const static uint16_t PORT = 9527;
// 最大同时连接请求数
const static int BACKLOG = 10;
// 最大关注事件数
const static int MAX_EVENTS = 10;

// 设置非阻塞
void set_nonblocking(int sockfd)
{
    int opts = fcntl(sockfd,F_GETFL);
    if(opts<0)
    {
        perror("fcntl get");
        return;
    }
    opts = opts|O_NONBLOCK;
    if(fcntl(sockfd,F_SETFL,opts)<0)
    {
        perror("fcntl set");
        return;
    }
}

// 使用触发事件的IO
void do_use_fd(int clientfd)
{
    const char str[] = "Cross the Great Wall,I come the new world.\n";
    if(send(clientfd,str,sizeof(str),0) == -1)
    {
        perror("send");
    }
    // close(clientfd);
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in addr;
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket");
        return 1;
    }
    set_nonblocking(sockfd);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&addr.sin_zero,8);
    if(bind(sockfd,(struct sockaddr *)&addr,sizeof(struct sockaddr))==-1)
    {
        perror("bind");
        return 2;
    }

    if(listen(sockfd,BACKLOG)==-1)
    {
        perror("listen");
        return 3;
    }

    struct epoll_event ev,events[MAX_EVENTS];
    int nfds,epollfd;

    // 创建epoll 事件列表,初始化大小
    epollfd = epoll_create(MAX_EVENTS);
    if(epollfd == -1)
    {
        perror("epoll create");
        return 4;
    }

    // 服务器socket fd
    ev.events = EPOLLIN;
    ev.data.fd = sockfd;
    if(epoll_ctl(epollfd,EPOLL_CTL_ADD,sockfd,&ev)==-1)
    {
        perror("epoll_ctl serv fd");
        return 5;
    }

    while(true)
    {
        // 等待IO事件
        printf("epoll_wait starting...\n");
        // 阻塞等待
        nfds = epoll_wait(epollfd,events,MAX_EVENTS,-1);

        if(nfds == -1)
        {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }
        printf("epoll_wait returned ,nfds = %2d\n",nfds);

        for(int n = 0; n < nfds; ++n)
        {
            // 出错
            if((events[n].events & EPOLLERR) ||
                    (events[n].events & EPOLLHUP) ||
                    (!(events[n].events & EPOLLIN)))
            {
                perror("epoll error");
                close(events[n].data.fd);
                continue;
            }
            // 新连接
            else if(events[n].data.fd == sockfd)
            {
                // 造成事件饥饿
                // 因为直到errno为EAGAIN或者将要阻塞，才会返回
                while(true)
                {
                    struct sockaddr in_addr;
                    socklen_t in_sz;
                    int infd;
                    if((infd=accept(sockfd,&in_addr,&in_sz))==-1)
                    {
                        // 直到下次IO事件到来,退出循环
                        if((errno == EAGAIN)||
                                (errno == EWOULDBLOCK))
                        {
                            break;
                        }
                        else
                        {
                            perror("accept");
                            break;
                        }
                    }
                    // 设置非阻塞
                    set_nonblocking(infd);
                    ev.events = EPOLLIN | EPOLLET;//边沿触发
                    ev.data.fd = infd;
                    // 添加感兴趣的IO事件
                    if(epoll_ctl(epollfd,EPOLL_CTL_ADD,infd,&ev) == -1)
                    {
                        perror("epoll_ctl conn_sock");
                        exit(EXIT_FAILURE);
                    }
                }
                continue;
            }
            else
            {
                // 不断循环读，会到
                bool done = false;
                while(true)
                {
                    // 读取内容
                    ssize_t count = 0;
                    // 减小数据量以触发信号
                    char buf[16];
                    count = read(events[n].data.fd,buf,sizeof(buf));
                    if(count == -1)
                    {
                        // 读取了所有数据，返回事件循环
                        // 输出后,直接完成,跳到结束连接处
                        if(errno==EAGAIN)
                        {
                            perror("read");
                            done = true;
                        }
                        break;
                    }
                    else if(count == 0)
                    {
                        // 对方关闭了连接
                        done = true;
                        break;
                    }
                    // 输出内容
                    fwrite(buf,1,count,stdout);
                }
                // 完成会话
                if(done)
                {
                    printf("close the connection:%2d\n",events[n].data.fd);
                    close(events[n].data.fd);
                }
            }

        }
    }

    close(sockfd);


    return 0;
}
