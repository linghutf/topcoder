#include "us.h"

int main(int argc,char *argv[])
{
    struct sockaddr_un addr;
    int sfd;
    ssize_t numRead;
    char buf[BUFSIZ];

    sfd = socket(AF_UNIX,SOCK_STREAM,0);
    assert(sfd!=-1);

    bzero(&addr,sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;

    strncpy(addr.sun_path,SV_SOCK_PATH,sizeof(addr.sun_path)-1);

    assert(connect(sfd,(struct sockaddr *)&addr,sizeof(struct sockaddr_un))!=-1);

    ssize_t n = 0;
    while(fgets(buf,BUFSIZ,stdin)>0){
        numRead = strlen(buf);
        buf[--numRead]='\0';
        if((n=write(sfd,buf,numRead))!=numRead){
            printf("n:%ld,numRead:%ld\n",n,numRead);
        }
        memset(buf,0,BUFSIZ);
    }
    assert(numRead != -1);
    close(sfd);

    return 0;
}
