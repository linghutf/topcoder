#include <stdio.h>
#include <stdlib.h>

void saygoodbye()
{
    printf("bye.\n");
}
int main(int argc, char *argv[])
{
    printf("1\n");
    atexit(saygoodbye);
    return 0;
}
