/**
 * 子进程不继承父进程的锁
 * 进程结束时锁全部释放
 *
 * 两个进程锁和全局变量都复制了一份
 * 两个读取的值并不相同
 * mutex 睡眠锁
 * rwlock trylock非阻塞式,lock阻塞式
 * spinlock 自旋锁，不让出cpu进行睡眠
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

//int shared_num = 0;//在bss段
//static int c,d=12;//c在bss段,d在data段

void testcase_spinlock()
{
    int res = 0; //共享变量,会发生复制
    //改成使用共享内存测试
    pthread_spinlock_t spinlock;
    pthread_spin_init(&spinlock,PTHREAD_PROCESS_SHARED);//PTHREAD_PROCESS_PRIVATE只支持在亲缘关系之间

    pid_t pid;
    if((pid=fork())<0){
        printf("create process ERROR!\n");
        return;
    }else if(pid>0){
        printf("[%d]addr:%p\n",getpid(),&spinlock);
        pthread_spin_lock(&spinlock);
        while(res<5){
            printf("father:[0x%p]%d\n",&res,++res);
            sleep(1);
        }
        pthread_spin_unlock(&spinlock);

    }else{
        sleep(2);
        printf("child[%d],addr:%p\n",getpid(),&spinlock);

        int i = 5;
        do{
            pthread_spin_lock(&spinlock);//两个进程锁不一样,shared_num也不一样
            printf("child:[0x%p]%d\n",&res,res);
            pthread_spin_unlock(&spinlock);
        }while(--i>0);
        printf("child condition Ok.run over!\n");
    }

    waitpid(pid,NULL,WUNTRACED);
    pthread_spin_destroy(&spinlock);
}

void testcase_rwlock()
{
    int shared_num = 0;
    pid_t pid;
    pthread_rwlock_t mtx;

    if(pthread_rwlock_init(&mtx,PTHREAD_PROCESS_PRIVATE)!=0){
        printf("lock init ERROR!\n");
        return ;
    }


    if((pid=fork())<0){
        printf("create process error!\n");
        return ;
    }else if(pid>0){
        printf("[%d]addr:%p\n",getpid(),&mtx);
        pthread_rwlock_wrlock(&mtx);
        while(shared_num<5){
            printf("father:[0x%p]%d\n",&shared_num,++shared_num);
            sleep(1);
        }
        pthread_rwlock_unlock(&mtx);

    }else{
        sleep(2);
        printf("child[%d],addr:%p\n",getpid(),&mtx);

        int i = 5;
        do{
            pthread_rwlock_rdlock(&mtx);//两个进程锁不一样,shared_num也不一样
            printf("child:[0x%p]%d\n",&shared_num,shared_num);
            pthread_rwlock_unlock(&mtx);
        }while(--i>0);
        printf("child condition Ok.run over!\n");
    }

    waitpid(pid,NULL,WUNTRACED);
    pthread_rwlock_destroy(&mtx);
}

int main(int argc, char *argv[])
{
#define SPIN_TEST

#ifdef RWLOCK_TEST
    printf("读写锁测试:\n");
    testcase_rwlock();
#endif
#ifdef SPIN_TEST
    printf("自旋锁测试:\n");
    testcase_spinlock();
#endif
    return 0;
}
