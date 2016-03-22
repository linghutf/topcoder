/**
 * Fisher Yates 随机算法
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b)
{
    int t = *a;
    *a=*b;
    *b=t;
}

void suffle(int a[],int len)
{
    srand(time(NULL));
    int i,j;

    for(i=0;i<len;++i){
        j = i+rand()%(len-i); //生成[i,len)之间的随机数
        swap(a+i,a+j);
    }
}

void testcase()
{
    int a[54];
    int len =54;
    int i;
    for(i=0;i<len;++i)
        a[i]=i+1;

    suffle(a,len);

    for(i=0;i<len;++i)
        printf("%3d",a[i]);
    putchar('\n');
}

int main(int argc, char *argv[])
{
    testcase();

    return 0;
}
