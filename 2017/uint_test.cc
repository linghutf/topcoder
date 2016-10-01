/**
 *
 * 测试无符号的循环
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    // ERROR 循环不会终止
    for(size_t i=10;i>=0;--i)
    {
        printf("%lu\n",i);
    }
    return 0;
}
