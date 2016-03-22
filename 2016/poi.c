#include <stdio.h>

int main(int argc, char *argv[])
{
    short *p,*q;
    short arr[15]={0};
    p=q=arr;
    p++;
    printf("%d\n",(char*)p-(char*)q);
    return 0;
}
