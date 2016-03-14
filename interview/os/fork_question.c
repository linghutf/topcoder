#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    for(i=0;i<2;++i)
    {
        fork();
        /**
         *            p ;原始父进程
         *i;0      p      c ;执行printf部分,buffer缓存1个
         *i:1    p   c1 c   c2 ;buffer copy到c1和c2
         *
         */
        printf("ppid=%d,pid=%d,i=%d\n",getppid(),getpid(),i);
        //printf("-");
    }
    sleep(10);
    return 0;
}
