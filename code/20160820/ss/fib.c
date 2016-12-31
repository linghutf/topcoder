#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>

long elapsed(struct timeval * s,struct timeval * t)
{
    return (t->tv_sec-s->tv_sec)*1000+(t->tv_usec-s->tv_usec)/1000;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    struct timeval s,t;
    gettimeofday(&s,NULL);
    long tmp = 0,a=1,b=1;
    for(int i=3;i<=n;++i)
    {
        tmp = a + b;
        a = b;
        b = tmp;
    }
    gettimeofday(&t,NULL);
    printf("%ld,time:%ld\n",b,elapsed(&s,&t));
    return 0;
}
