#include <stdio.h>

int factor(int n)
{
    return n*(n-1);
}

int main()
{
    int a[]={13,14,15,16,17,18};
    int len=sizeof(a)/sizeof(a[0]);
    int added = 58;

    for(int i=0;i<len;++i){
        for(int j=a[i]-1;j>=1;--j){
            if((factor(a[i])-factor(j))==added){
                printf("%2d\n",a[i]);
            }
        }
    }

    return 0;
}
