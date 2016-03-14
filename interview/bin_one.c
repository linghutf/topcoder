#include <stdio.h>
#include <stdlib.h>

int NumberOf1_Regular(int n)
{
    int cnt = 0;
    unsigned int flag = 1;
    while(flag){
        if(n&flag)
            cnt++;
        flag<<=1;
    }
    return cnt;
}

int NumberOf1(int n)
{
    int cnt = 0;
    while(n){
        ++cnt;
        n = (n-1)&n;
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    printf("%d %d\n",NumberOf1_Regular(n),NumberOf1(n));
    return 0;
}
