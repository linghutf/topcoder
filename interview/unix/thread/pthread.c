#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

static void stop(int signo)
{
    if(signo == SIGUSR1){
        printf("[EXIT]pid:%lu,thread:%lu\n",(unsigned long)getpid(),(unsigned long)pthread_self());
        pthread_exit(NULL);
    }
}

void print()
{
    signal(SIGUSR1,stop);

    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("current pid:%lu,thread:%lu\n",(unsigned long)pid,(unsigned long)tid);

    int i=0;
    while(++i){
        sleep(1);
        printf("[%lu]:%d\n",(unsigned long)tid,i);
    }
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_create(&tid,NULL,(void*)print,NULL);
    //main thread
    printf("main pid:%lu,thread:%lu\n",(unsigned long)getpid(),(unsigned long)pthread_self());
    //wait
    pthread_join(tid,NULL);
    return 0;
}
