#include <sys/time.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct timeval t;
    gettimeofday(&t,NULL);
    return 0;
}
