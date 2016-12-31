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
    struct sockaddr_in addr,r_addr;
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket");
        return 1;
    }

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

    socklen_t sin_sz = sizeof(struct sockaddr_in);

    struct epoll_event ev,events[MAX_EVENTS];
    int conn_sock,nfds,epollfd;

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
        printf("epoll_wait starting...\n");
        nfds = epoll_wait(epollfd,events,MAX_EVENTS,-1);
        if(nfds == -1)
        {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }
        printf("epoll_wait returned ,nfds = %2d\n",nfds);

        for(int n = 0; n<nfds;++n)
        {
            if(events[n].data.fd == sockfd)
            {
                // 等待连接
                conn_sock = accept(sockfd,(struct sockaddr *)&r_addr,&sin_sz);
                if(conn_sock == -1)
                {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                // 设置非阻塞
                set_nonblocking(conn_sock);
                ev.events = EPOLLIN | EPOLLET;//边沿触发
                ev.data.fd = conn_sock;
                // 添加感兴趣的IO事件
                if(epoll_ctl(epollfd,EPOLL_CTL_ADD,conn_sock,&ev) == -1)
                {
                    perror("epoll_ctl conn_sock");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                // 关闭非服务器的连接
                // 也就是如果客户端发来信息，判断不是server fd,立刻关闭该链接
                do_use_fd(events[n].data.fd);
            }
        }
    }

    return 0;
}
