#include "header.hh"

#define QLEN 10

int main(int argc,char *argv[])
{
    int fd;
    int len,err,rval;

    struct sockaddr_un un;

    memset(&un,0,sizeof(un));

    unlink(SOCK_PATH);

    un.sun_family = AF_UNIX;
    strcpy(un.sun_path,SOCK_PATH);
    if((fd=socket(AF_UNIX,SOCK_STREAM,0))<0){
        perror("unix domain socket ERROR!");
        exit(EXIT_FAILURE);
    }


    len = offsetof(struct sockaddr_un,sun_path) +strlen(un.sun_path);

    if(bind(fd,(struct sockaddr *)&un,len)<0){
        rval = -2;
        goto errout;/*
        perror("socket bind ERROR!");
        exit(EXIT_FAILURE);
        */
    }
    //printf("now listen....\n");
    if(listen(fd,QLEN)<0){
        rval = -3;
        goto errout;
    }

    if(clifd=accept(fd,(struct sockaddr *)&un,len)<0){
        rval = -4;
        goto errout;
    }

    if(stat(un.sun_path,&statbuf)<0){
        rval = -1;
        goto errout;
    }
    if(S_ISSOCK(statbuf.st_mode)==0){
        rval = -1;
        goto errout;
    }
    if(uidptr != NULL){

    }
errout:
    err = errno;
    close(fd);
    errno = err;
    return rval;
}
