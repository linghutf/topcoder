#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    if((pid=fork())<0){
        fprintf(stderr,"fork ERROR.\n");
    }else if(pid==0){
        sleep(1);
        int s=0;
        for(int i=0;i<=100;++i)
            s+=i;
        printf("sum:%4d pid:%10d\n",s,getpid());
    }else{
        //int ret = waitpid(pid);//返回子进程的id
        int ret = wait();//返回-1表示成功
        printf("waiting finished.return:%d\n",ret);
    }
    return 0;
}
