/*
 * 全局变量和静态变量在静态存储区
 */
#include <stdio.h>
#include <stdlib.h>

//全局变量
//内存地址分配从低到高
int a = 1;//0认为没有初始化，在bss段
int b = 2;
int e = 3;

//静态变量
//未初始化的变量内存地址与全局变量相隔一个int指针地址
//内存地址分配从低到高
static int c;
static int d=1;//初始化后紧挨着全局变量区

void test()
{
    int *p = (int*)malloc(sizeof(int));
    int *q = (int*)malloc(sizeof(int));
    printf("Heap:\n");
    printf("%p\n%p\n",p,q);
    free(p);
    free(q);

    printf("Stack:\n");
    int f=2;
    int g=4;
    printf("%p\n%p\n",&f,&g);
}

int main(int argc, char *argv[])
{
    printf("Global:\n");
    printf("%p\n%p\n%p\n%p\n%p\n",&a,&b,&e,&c,&d);

    int *p = (int*)malloc(sizeof(int));
    int *q = (int*)malloc(sizeof(int));
    printf("Heap:\n");
    printf("%p\n%p\n",p,q);
    free(p);
    free(q);

    printf("Stack:\n");
    int f=2;
    int g=3;
    printf("%p\n%p\n",&f,&g);

    printf("Func:\n");
    test();//栈区分配的地址比main中局部变量低

    return 0;
}
