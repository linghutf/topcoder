#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t g_mtx = PTHREAD_MUTEX_INITIALIZER;

int g_count = 0;
int g_flag = 0;

void * foo(void * flag)
{
    while(*(_Bool*)flag){
        pthread_mutex_lock(&g_mtx);
        g_count+=2;
        printf("cur:%4d\n",g_count);
        pthread_mutex_unlock(&g_mtx);
        sleep(2);
    }
    return NULL;
}

void * bar(void * flag)
{
    while(*(_Bool*)flag){
        pthread_mutex_lock(&g_mtx);
        --g_count;
        printf("cur:%4d\n",g_count);
        pthread_mutex_unlock(&g_mtx);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1,t2;
    int s;
    _Bool flg = 1;

    s = pthread_create(&t1,NULL,foo,&flg);
    assert(s==0);

    s = pthread_create(&t2,NULL,bar,&flg);
    assert(s==0);

    //pthread_sleep();
    sleep(5);
    // 改变flag
    pthread_mutex_lock(&g_mtx);
    flg=0;
    pthread_mutex_unlock(&g_mtx);

    s = pthread_join(t1,NULL);
    assert(s==0);

    s = pthread_join(t2,NULL);
    assert(s==0);

    return 0;
}
