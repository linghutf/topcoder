/**
 * 拷贝NULL,NULL拷贝
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int * p = NULL;
    int n = 20;
    //memcpy(p,&n,sizeof(n));// coredump
    memcpy(&n,p,sizeof(*p));//null,coredump
    printf("%d\n",n);

    return 0;
}
