#include <stdio.h>

int bsearch(int data[],int x,int y,int v)
{
    int m;
    while(x<y){
        m = x+(y-x)/2;
        printf("x:%2d,y:%2d,m:%2d\n",x,y,m);
        if(data[m]==v) return m;
        else if(data[m]>v) y = m-1;
        else x = m;
    }
    return -1;
}

int main()
{
     int a[]={1,1,2,3,4,6};
     int len = sizeof(a)/sizeof(a[0]);
     printf("%d\n",bsearch(a,0,len,5));
     return 0;
}
