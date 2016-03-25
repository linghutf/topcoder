/**
 *
 * 多进程使用共享内存通信
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHM_SIZE 4096 //页的整数倍，多余的部分将不能访问
#define SHM_MODE 0600 //user r/w

//寻找共享存储，并修改
void handle(int shmid,size_t size,char *str)
{
    char *shm_addr=shmat(shmid,0,0);
    if(shm_addr ==(void*)-1){
        printf("shaat error\n");
        return;
    }
    printf("[当前内容]%s\n",(char*)shm_addr);

    //修改为新值
    int len = strlen(str);
    memcpy(shm_addr,(void*)str,len);
}

int main()
{
    pid_t pid;
    int shmid;

    if((shmid = shmget(IPC_PRIVATE,SHM_SIZE,SHM_MODE))<0){
        printf("create shared memory ERROR\n");
        return -2;
    }
    //shm
    if((pid=fork())<0){
        printf("create process error\n");
        return -1;
    }else if(pid==0){
        char str[SHM_SIZE];
        int i=0;
        while(i<10){
            snprintf(str,SHM_SIZE,"[pid:%d]%d:%s",getpid(),++i,"来自子进程修改");
            handle(shmid,SHM_SIZE,str);
            sleep(1);
        }
    }else{
        char str[SHM_SIZE];
        int i=0;
        while(i<20){
            snprintf(str,SHM_SIZE,"[%d]%d:%s",getpid(),++i,"来自父进程修改");
            handle(shmid,SHM_SIZE,str);
            sleep(1);
        }

        int status;
        wait(&status);
        printf("子线程退出状态:%d\n",status);

        if(shmctl(shmid,IPC_RMID,0)<0)
            printf("rm shm error.\n");
    }
    return 0;
}
