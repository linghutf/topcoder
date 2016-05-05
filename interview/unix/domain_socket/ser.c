#include "us.h"

int main(int argc,char *argv[])
{
    struct sockaddr_un addr;
    int sfd,cfd;
    ssize_t numRead;
    char buf[BUFSIZ];

    sfd = socket(AF_UNIX,SOCK_STREAM,0);
    assert(sfd != -1);

    if(remove(SV_SOCK_PATH) == -1 && errno != ENOENT){
        printf("remove-%s ERROR!\n",SV_SOCK_PATH);
        return -1;
    }

    bzero(&addr,sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;

    strncpy(addr.sun_path,SV_SOCK_PATH,sizeof(addr.sun_path)-1);


    bzero(&addr,sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;

    strncpy(addr.sun_path,SV_SOCK_PATH,sizeof(addr.sun_path)-1);

    assert(bind(sfd,(struct sockaddr *)&addr,sizeof(struct sockaddr_un))!=-1);

    assert(listen(sfd,0)!=-1);

    while(1){
        cfd = accept(sfd,NULL,NULL);
        assert(cfd!=-1);

        while((numRead=read(cfd,buf,BUFSIZ))>0){
            printf("%s\n",buf);
            if(strncmp(buf,"bye",3)==0) break;
            bzero(buf,BUFSIZ);
        }
        if(numRead==-1){
            printf("read ERROR!\n");
            break;
        }
        assert(close(cfd)!=-1);
    }
    close(sfd);
    return 0;
}

