#include <stdio.h>

static int a;    //未初始化的静态变量 bss段
static int b = 10;//初始化            data段

int c;//未初始化的全局变量           COM段(编译期),链接后bss段
int d=12;                           //data段

int main(int argc, char *argv[])
{
    static int e;//main中             bss段
    static int f = 13;              //data段
    printf("a:0x%p\nb:0x%p\nc:0x%p\nd:0x%p\n",&a,&b,&c,&d);
    printf("e:0x%p\nf:0x%p\n",&e,&f);
    return 0;
}
