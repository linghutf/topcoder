#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if(pid>0){
        /**
         * pid为子进程的id
         * getpid取当前进程id
         */
        printf("父进程: pid:%d,getpid:%d,getppid:%d\n",pid,getpid(),getppid());
    }else{
        /**
         * pid为0，表明是子进程运行
         * getppid:取父进程
         */
        printf("子进程: pid:%d,getpid:%d,getppid:%d\n",pid,getpid(),getppid());
        sleep(1);
    }
    /**
     * 失败返回0或-1
     * 成功返回终止的进程id,就是子进程的id
     */
    printf("waitid:%d\n",wait());
    return 0;
}
