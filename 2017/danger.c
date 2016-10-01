/**
 * 测试可能导致崩溃操作
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("%i,%d\n",NULL,NULL);

    //char a[100]={0};
    //free(a);// 崩溃

    //printf("%s\n",NULL,0x1234); // 崩溃


    return 0;
}
