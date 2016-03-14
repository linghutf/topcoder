#include <iostream>

#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t child = fork();
    char s[]="hello";
    if(child==0){
        s[0]='t';
        std::cout<<"这是父进程:"<<s<<std::endl;
    }else if(child>0){
        s[1]='m';
        std::cout<<"这是子进程id="<<child<<",父id="<<getpid()<<s<<std::endl;
    }
    return 0;
}
