/**
 * 二进制中有多少个1
 *
 * 每次减去1，相与得到最高位是否为1
 */
#include <stdio.h>

int num_of_bit(int n)
{
    int cnt = 0;
    while(n)
    {
        n&=(n-1);
        ++cnt;
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    for(int i = -10;i<10;++i)
    {
        printf("%2d:%2d\n",i,num_of_bit(i));
    }

    return 0;
}
