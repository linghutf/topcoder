#include <stdio.h>
#include <stdlib.h>

int a[10];
_Bool book[10];
int n;

void dfs(int step)
{
    int i;
    if(step==n){
        for(i=0;i<step;++i)
            printf("%3d",a[i]);
        printf("\n");
    }else{
        for(i=1;i<=n;++i){//一个个数尝试
            /**
             * book: [0,n-1]
             * i:    [1,n]
             */
            if(!book[i-1]){//没有使用
                book[i-1]=1;//标记i号使用
                a[step]=i;//step步选择内容填入i
                dfs(step+1);//处理下一个
                book[i-1]=0;//退回
            }
        }
    }
}

int main(int argc, char *argv[])
{
    n = 3;
    dfs(0);
    return 0;
}
