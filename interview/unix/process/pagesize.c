#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pagesize = getpagesize();
    printf("当前系统页大小:%8dbyte.\n",pagesize);
    return 0;
}
