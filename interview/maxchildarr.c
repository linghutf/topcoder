#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int a[],int len,int *begin,int *end);

int main(int argc, char *argv[])
{
    int a[]={1,-2,3,10,-4,-7,2,-5};
    int len=sizeof(a)/sizeof(a[0]);
    int i,j;
    int s = maxSubArray(a,len,&i,&j);
    for(int k=i;k<j;++k)
        printf("%3d",a[k]);
    printf("\nsum=%4d\n",s);

    return 0;
}

int maxSubArray(int a[],int len,int *begin,int *end)
{
    if(a==NULL||len<=0)
        return -1;
    int sum = 0;
    int max = ~(1<<31);
    int cur = 0;
    *begin = 0;
    while(cur<len){
        sum+=a[cur++];//尝试第一位
        if(sum>max){
            max=sum;
        }else if(sum<0){
            sum=0;
            *begin = cur;
        }
    }
    *end = cur-1;
    return sum;
}


