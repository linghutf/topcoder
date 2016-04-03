#include <stdio.h>

struct A{
    long a; //8个字节
    short b; //内存对齐 4个字节
    int c; // 4个字节
    int *d; //64位下8个字节
};

int main(int argc, char *argv[])
{
    printf("int:%lu.,long:%lu,int*:%lu\n",sizeof(int),sizeof(long),sizeof(int*));
    printf("size:%lu\n",sizeof(struct A));
    return 0;
}
