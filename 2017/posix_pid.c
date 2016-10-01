#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <pthread.h>

#include <stdio.h>

void * foo()
{
    printf("pid:%d,tid:%lu\n",getpid(),pthread_self());
    return NULL;
}

int main(int argc, char *argv[])
{

    pthread_t t1,t2;
    pthread_create(&t1,NULL,foo,NULL);
    pthread_create(&t2,NULL,foo,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}
