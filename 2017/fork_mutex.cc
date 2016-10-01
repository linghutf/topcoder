/**
 * 测试进程可不可以使用互斥量
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>

#include <thread>
#include <mutex>

int g_count = 0;
std::mutex g_mtx;


int main(int argc, char *argv[])
{
    pid_t child;

    if((child=fork())<0){
        printf("error fork.\n");
        return 1;
    }else if(child==0){
        for(int i=0;i<10;++i)
        {
            g_mtx.lock();
            g_count--;//从父线程复制了一份
            printf("count:%d\n",g_count);
            g_mtx.unlock();
            sleep(1);
        }
    }else{
        for(int i=0;i<10;++i)
        {
            g_mtx.lock();
            g_count++;
            printf("count:%d\n",g_count);
            g_mtx.unlock();
            sleep(1);
        }
    }
    waitpid(child,NULL,0);
    return 0;
}
