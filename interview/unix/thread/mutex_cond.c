/**
 * 一定要在改变线程状态后再给线程发信号
 */
#include <stdio.h>
#include <pthread.h>

#include <string.h>

#define MSGLEN 100

struct msg{
    struct msg *m_next;
    char *data;
};

struct msg *workq;

pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg()
{
    struct msg *mp;
    while(1){
        pthread_mutex_lock(&qlock);
        while(workq == NULL)
            pthread_cond_wait(&qready,&qlock);
        mp = workq;
        printf("date:%s\n",mp->data);
        workq = mp->m_next;
        pthread_mutex_unlock(&qlock);
    }
}

void enqueue_msg(struct msg *mp)
{
    pthread_mutex_lock(&qlock);
    mp->m_next = workq;
    workq = mp;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}

int main(int argc, char *argv[])
{
    pthread_t pid1,pid2;

    struct msg nmp;

    char s[]="hello,pthread!";
    nmp.data = s;
 //   strcpy(nmp.data,s);
    pthread_create(&pid1,0,enqueue_msg,(void*)&nmp);
    pthread_create(&pid2,0,process_msg,NULL);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);

    return 0;
}
