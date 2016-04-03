#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open("test",0666|O_NONBLOCK);
    if(fd==-1){
        perror("open");
        return 1;
    }
    char buf[BUFSIZ];
    ssize_t len;
    while((len=read(fd,buf,BUFSIZ))>0){
        printf(buf);
    }
    close(fd);
    return 0;
}
