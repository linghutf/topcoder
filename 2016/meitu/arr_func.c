/**
 * 一个指针数组，指向一个函数，参数为整形，返回整形
 */

#include <stdio.h>

typedef int (*Pfunc)(int);
Pfunc pfunc[10];

int neg(int a)
{
    return -a;
}

int dis(int a)
{
    return ~a;
}
int main(int argc, char *argv[])
{
    pfunc[0] = neg;
    pfunc[1] = dis;
    printf("%d,%d\n",pfunc[0](2),pfunc[1](2));
    return 0;
}
