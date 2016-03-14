#include <stdio.h>

inline void swap(int *a,int *b)
{
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void InsertSort(int a[],size_t len)
{
    size_t i,j;
    for(i=1;i<len;++i){
        /**i=1: j a[1] a[0] 有序
         *
         * i=2: j a[2] a[1] 比较
         *         or  a[1] a[0] 当a[2]<a[0]
         *
         * i=3: j a[3] a[2]
         *         or  a[2] a[1] 当a[3]<a[1]
         *             or   a[1] a[0] 当a[3]<a[0]
         * ...
         */
        for(j=i;j>0&&a[j]<a[j-1];--j)
            swap(a+i,a+j-1);
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
