#include <stdio.h>
#include <math.h>

struct point{
    int x,y;
};

int distance(const struct point *a,const struct point *b)
{
    return sqrt(pow(a->x-b->x,2)+pow(a->y-b->y,2));
}

int main()
{
    struct point a[4],*p,*d;
    int r,i,cnt=0,n=4;
    scanf("%d",&r);
    for(i=0;i<n;++i){
        p=a+i;
        scanf("%d %d",&(p->x),&(p->y));
    }
    d=a+n-1;
    for(i=0;i<n-1;++i){
        p=a+i;
        if(distance(p,d)<=r)
            cnt++;
    }
    printf("%dx\n",cnt);
    return 0;
}