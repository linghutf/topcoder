#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *str[10]={
        "hello",//没有填充0,没有10个位置
        "tencent"
    };
    char *p = str[0];
    printf("%s:%lu\n",p+10,strlen(p+10));
    return 0;
}
