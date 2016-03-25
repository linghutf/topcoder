/**
 * 子进程不继承父进程的锁
 * 进程结束时锁全部释放
 *
 * 两个进程锁和全局变量都复制了一份
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

int shared_num = 0;


int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_rwlock_t mtx;

    if(pthread_rwlock_init(&mtx,NULL)!=0){
        printf("lock init ERROR!\n");
        return -3;
    }

    if((pid=fork())<0){
        printf("create process error!\n");
        return -1;
    }else if(pid>0){
        FILE *fp = fopen("result1","w");
        fprintf(fp,"[%d]addr:%p\n",getpid(),&mtx);
        fclose(fp);
        pthread_rwlock_wrlock(&mtx);
        while(shared_num<5){
            printf("father:%d\n",++shared_num);
            sleep(1);
        }
        pthread_rwlock_unlock(&mtx);

    }else{//改成读写锁没有机会运行
        sleep(2);
        FILE *fp = fopen("result2","w");
        fprintf(fp,"child[%d],addr:%p\n",getpid(),&mtx);
        fclose(fp);

        do{
            pthread_rwlock_rdlock(&mtx);//两个进程锁不一样,shared_num也不一样
            printf("child:%d\n",shared_num);
            pthread_rwlock_unlock(&mtx);
        }while(shared_num!=5);
        printf("child condition Ok.run over!\n");
    }

    waitpid(pid);
    pthread_rwlock_destroy(&mtx);


    return 0;
}
