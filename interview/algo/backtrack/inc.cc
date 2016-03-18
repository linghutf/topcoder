#include <cstdio>

int main(int argc, char *argv[])
{
    int a = 5;
    ++(a++);
    std::printf("%d\n",a);
    return 0;
}
