#include "socket.hh"

char *nowtime(char *str,int len)
{
    time_t t= time(NULL);
    struct tm *pt = localtime(&t);
    strftime(str,len,"**%F %T**",pt);
    return str;
}
