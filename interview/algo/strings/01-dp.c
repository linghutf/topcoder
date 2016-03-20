#include <stdio.h>
#include <stdlib.h>

#define N 500
#define M 100000

int need[N]={0};
int value[N]={0};
int d[N][M]={0};

int max(int a,int b)
{
    return a<b?b:a;
}

int main(int argc, char *argv[])
{
    unsigned int n,m;
    scanf("%d%d",&n,&m);
    if(n>N||m>M) return -1;
    int i,j;
    for(i=0;i<n;++i){
        scanf("%d%d",need+i,value+i);
    }
    for(j=0;j<=m;++j)
        d[0][j]=0;

    //int **d = (int**)malloc
    for(i=1;i<=n;++i){
        for(j=m;j<=need[i-1];++j){
            d[i][j]=max(d[i-1][j],d[i-1][j-need[i-1]]+value[i-1]);
        }
    }
    printf("%d\n",d[n][m]);
    return 0;
}
