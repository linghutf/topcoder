#include <stdio.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
    printf("最大文件描述符数量%lu\n",(unsigned long)FD_SETSIZE);
    return 0;
}
