/**
 * 消息队列测试
 *
 */
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <pthread.h>

#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * foo(void * arg)
{
    sleep(3);
    char msgs[BUFSIZ];
    //size_t msg_len = 0;
    ssize_t len = 0;
    mqd_t mq = *(mqd_t*)arg;

    for(int i=0;i<10;++i)
    {
        len = mq_receive(mq,msgs,BUFSIZ,NULL);
        msgs[len]='\0';
        printf("[recv] %s\n",msgs);
    }
}

int main(int argc, char *argv[])
{
    mode_t omask = umask(0);
    printf("mask:%d",omask);
    struct mq_attr attr;
    attr.mq_maxmsg = 8;
    attr.mq_msgsize = 1024;
    attr.mq_flags = 0;

    // 不能使用/tmp/mq之类的名字
    mqd_t mq = mq_open("/mq",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH,&attr);
    if(mq==-1)
    {
        perror("create mq ERROR");
        return 1;
    }
    umask(omask);

    pthread_t t;
    pthread_create(&t,NULL,foo,&mq);

    char msgs[BUFSIZ];
    int len = 0;

    for(int i=0;i<10;++i)
    {
        snprintf(msgs,BUFSIZ,"%d\n",i);
        len = mq_send(mq,msgs,strlen(msgs),0);
        printf("[send] %d\n",len);
    }

    pthread_join(t,NULL);
    sleep(3);
    mq_close(mq);

    return 0;
}
