/**
 * 测试memset 可否初始化非0值
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int len = 5;
    int a[len];
    memset(a,0,len*sizeof(int));//不可以初始化特殊值,-1可以
    for(int i=0;i<len;++i)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
