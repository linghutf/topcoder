#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
    socklen_t len;
    struct sockaddr_in servaddr,clientaddr;

    char buf[BUFSIZ];
    time_t ticks;

    int fd = socket(AF_INET,SOCK_STREAM,0);

    connect(fd,(struct sockaddr*)&addr,)
    return 0;
}
