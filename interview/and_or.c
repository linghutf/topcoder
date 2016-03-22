#include <stdio.h>

int main(int argc, char *argv[])
{
    int a=1,b=0,c=-1,d=0;
    d=++a||++b&&++c;//&&优先级高于||,根据短路原则,判断++a为真直接返回
    printf("%d\n",d);
    printf("%d\n",0||1&&1);//1,1&&1=1,0||1=1
    return 0;
}
