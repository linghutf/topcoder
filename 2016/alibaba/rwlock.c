#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>


int m=0,n=0;

int main()
{
    pid_t pid;
    pthread_rwlock_t a,b;
    pthread_rwlock_init(&a,NULL);
    pthread_rwlock_init(&b,NULL);

    if((pid=fork())==-1){
        printf("fork error!\n");
    }else if(pid==0){
        pthread_rwlock_wrlock(&b);
        printf("writing b...\n");
        n++;
        sleep(2);
        pthread_rwlock_unlock(&b);
        pthread_rwlock_rdlock(&a);
        printf("reading a...\n");
        printf("m:%2d\n",m);
        sleep(1);
        pthread_rwlock_unlock(&a);
    }else{
        pthread_rwlock_wrlock(&a);
        printf("writing a...\n");
        m++;
        sleep(2);
        pthread_rwlock_unlock(&a);
        pthread_rwlock_rdlock(&b);
        printf("reading b...\n");
        printf("n:%2d\n",n);
        sleep(1);
        pthread_rwlock_unlock(&b);
    }
    wait();
    pthread_rwlock_destroy(&a);
    pthread_rwlock_destroy(&b);
    return 0;
}
