#include <unistd.h>
#include <errno.h>
#include "rdwrn.h"

ssize_t readn(int fd,void *buffer,size_t n)
{
    ssize_t numRead;
    size_t totRead;
    char *buf = buffer;
    for(totRead = 0;totRead<n;){
        numRead = read(fd,buf,n-totRead);

        if(numRead == 0)
            return totRead;
        if(numRead == -1){
            if(errno == EINTR) //interrupted,restart read
                continue;
            else
                return -1;
        }
        totRead += numRead;
        buf += numRead;
    }
    return totRead;
}

ssize_t writen(int fd,void *buffer,size_t n)
{
    ssize_t numWritten;
    size_t totWritten;
    const char *buf = buffer;
    for(totWritten = 0;totWritten<n;){
        numWritten = write(fd,buf,n-totWritten);

        if(numWritten <= 0){
            if(numWritten == -1 && errno == EINTR)
                continue;
            else
                return -1;
        }
        totWritten += numWritten;
        buf += numWritten;
    }
    return totWritten;
}
