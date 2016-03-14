#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if(fork() && wait())
        printf(" world\n");
    else
        printf("hello");

    return 0;
}
