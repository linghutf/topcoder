#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

void handle();

void send_msg();

void recv_msg();

int main(int argc, char *argv[])
{
    int fd,connfd;
    socklen_t len;
    struct sockaddr_in servaddr,clientaddr;


    if((fd= socket(AF_INET,SOCK_STREAM,0))==-1){
        printf("socket ERROR!\n");
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADRR_ANY);//0.0.0.0
    servaddr.sin_port =htons(8001);

    if(bind(fd,(struct sockaddr*)&servaddr,sizeof(addr))==-1){
    }

    if(listen(fd,LISTENQ)==-1){
    }
    while(true){
        len = sizeof(clientaddr);
        if((connfd = accept(fd,(struct sockaddr*)&clientaddr,&len))!=-1){
            if((pid=fork())<0){
                printf("fork ERROR!\n");

            }else if(pid==0){
                handle();
            }
        }
    }
    return 0;
}

void handle()
{
    pid_t pid;
    if((pid=fork())<0){
    }else if(pid==0){
        while(1) send_msg();
    }else{
        while(1) recv_msg();
    }
}

void send_msg()
{

}

void recv_msg()
{
}
