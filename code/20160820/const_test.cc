#include <stdio.h>

int foo(int *p)
{
    *p = 3;
}

char *get_mem()
{
    char *p = "hello,world";//全局常量,c++警告
    return p;
}

void test()
{
    char *p=get_mem();
    printf("%s\n",p);
}

void test_const_cast()
{
    const int a = 1;
    // 去掉常量表达式的const属性，不再从地址取值
    int  *p = const_cast<int*>(&a);
    *p = 2;//未定义的行为
    // 错误
    //a = 3
    //地址一样;
    const bool is_equal = p==&a;//addr
    // 1 可能崩溃或值 1
    printf("a:%d *p:%d addr_is_equal:%d[1:yes]\n",a,*p,is_equal);
}

int main(int argc, char *argv[])
{
    int a = 10;
    int * p = &a;
    foo(p);
    test();
    test_const_cast();
    return 0;
}
