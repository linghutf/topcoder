#include "socket.hh"

int main(int argc, char *argv[])
{
    int cli_fd;
    int len;
    char buf[BUFSIZ];

    struct sockaddr_in addr,remoteaddr;
    bzero(&remoteaddr,sizeof(remoteaddr));

    remoteaddr.sin_family = AF_INET;
    remoteaddr.sin_addr.s_addr = inet_addr("127.0.0.1");//server host
    remoteaddr.sin_port = htons(8000);

    if((cli_fd=socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket");
        return 1;
    }

    if(connect(cli_fd,(struct sockaddr *)&remoteaddr,sizeof(struct sockaddr))<0){
        perror("connect");
        return 1;
    }

    socklen_t addrlen;
    if(getpeername(cli_fd,(struct sockaddr*)&addr,&addrlen)<0){
        perror("getpeername");
    }
    printf("connected to server:[%s:%d]\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));

    pid_t pid;
    if((pid=fork())<0){
        perror("fork");
    }else if(pid==0){
        int time_len = 30,rlen;
        while(1){
            nowtime(buf,time_len);
            rlen = strlen(buf);

            fgets(buf+rlen,BUFSIZ-rlen,stdin);

            len = send(cli_fd,buf,strlen(buf),0);
            if(strncmp("bye",buf+rlen,3)==0) goto stop;
            usleep(100);
        }
    }else{
        while(1){
            if((len = recv(cli_fd,buf,BUFSIZ,0))>0){
                buf[len]='\0';
                if(strncmp("bye",buf+len-4,3)==0) goto stop;
                printf("[recv]:%s",buf);
            }
            usleep(100);
        }
    }
stop:
    prctl(PR_SET_PDEATHSIG,SIGHUP);
    close(cli_fd);

    return 0;
}
