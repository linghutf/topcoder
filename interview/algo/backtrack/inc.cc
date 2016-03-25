//编译期间错误
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 5;
    ++(a++);
    std::printf("%d\n",a);
    return 0;
}
