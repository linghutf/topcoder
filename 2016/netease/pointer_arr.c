#include <stdio.h>
#include <stdlib.h>

#define COL 4

/**
 * 函数指针
 * = int func(int,int);
 * p = func
 *
 * 用法:
 * PFunc pf = func;
 * pf可以作为参数传递
 */
typedef int (*PFunc)(int,int);

/**
 * 指针数组
 * 指向整形数组的指针
 * row 表示这样的指针有多少个,也即多少行
 * COL 表示每个指针的有效地址范围，也即多少列
 *
 */
int (*ArrayPointer)[],int row);

/**
 * 数组指针
 * 用于 传递二维数组
 * 高维不能省略
 * int a[][col]
 * int a[][col][3d]
 */
void fun(int a[][COL],int row);

void fun3d(int a[][2][3],int row);

int main(int argc, char *argv[])
{
    int a[][4]={1,2,3,4,5,6,7,8};
    fun(a,2);

    return 0;
}

void fun(int a[][COL],int row)
{
    int i,j;
    for(i=0;i<row;++i)
        for(j=0;j<COL;++j)
            printf("%3d",a[i][j]);
    printf("\n");
}

void fun3d(int a[][2][3],int row)
{
}
