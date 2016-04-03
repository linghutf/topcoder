#include "socket.hh"


int main(int argc, char *argv[])
{
    int serv_fd,cli_fd;
    int len;
    char buf[BUFSIZ];
    struct sockaddr_in addr,remoteaddr;
    bzero(&addr,sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8000);

    if((serv_fd=socket(AF_INET,SOCK_STREAM,0))<0){
        perror("socket");
        return 1;
    }

    if(bind(serv_fd,(struct sockaddr *)&addr,sizeof(struct sockaddr))<0){
        perror("bind");
        return 1;
    }

    listen(serv_fd,5);

    socklen_t sin_size = sizeof(struct sockaddr_in);
    if((cli_fd=accept(serv_fd,(struct sockaddr *)&remoteaddr,&sin_size))<0){
        perror("accept");
        return 1;
    }
    printf("accept client:[%s:%d]\n",inet_ntoa(remoteaddr.sin_addr),ntohs(remoteaddr.sin_port));

    pid_t pid;
    if((pid=fork())<0){
        perror("fork");
    }else if(pid==0){//write,send
        int time_len=30,rlen;
        while(1){
            nowtime(buf,time_len);
            rlen = strlen(buf);
            fgets(buf+rlen,BUFSIZ-rlen,stdin);//get input
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
    close(serv_fd);

    return 0;
}
