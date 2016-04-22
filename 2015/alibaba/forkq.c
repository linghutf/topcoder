#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    fork() && fork() || fork();
    fork();
    sleep(10);
    return 0;
}
