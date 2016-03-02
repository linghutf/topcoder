#include <stdio.h>

int main(int argc, char *argv[])
{
    char i=2;
    char r=i&(~i);
    printf("%0x\n%0x\n%0x\n",i,~i,r);
    return 0;
}
