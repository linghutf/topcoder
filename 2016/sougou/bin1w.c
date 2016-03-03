#include <stdio.h>
#include <stdlib.h>

//位运算求整数二进制中1的个数
int count_bin_one(int n)
{
    int cnt=0;
    while(n){
        cnt++;
        n&=(n-1);
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    int a=atoi(argv[1]);
    //int b=atoi(argv[2]);
    //printf("%d %d\n",count_bin_one(a),count_bin_one(b));
    int cnt=0;
    for(int i=1;i<=a;++i)
        cnt+=count_bin_one(i);
    printf("%d\n",cnt);
    return 0;
}
