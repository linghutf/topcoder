#include <stdio.h>

int sumOfBits(int n)
{
    int s=0;
    while(n){
        s+=n%10;
        n/=10;
    }
    return s;
}

int factOfBits(int n){
    int r=1;
    while(n){
        r*=(n%10);
        n/=10;
    }
    return r;
}

int main()
{
    int a=1000;
    int t = 0;
    int sumcnt = 0;
    int factcnt = 0;
    for(int i=1;i<=a;++i){
        t = sumOfBits(i);
        //printf("sum:%2d---%2d\n",t,t%10);
        if(t%10==0) sumcnt++;

        t = factOfBits(i);
        if(t==0) factcnt++;
    }
    printf("sum result:%d\nfact result:%d\n",sumcnt,factcnt);
    return 0;
}
