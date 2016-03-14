#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t fib(uint64_t n)
{
    if(n<=2)
        return 1;
    uint64_t a=1,b=1,t,i;
    for(i=2;i<n;++i){
        t=a+b;
        a=b;
        b=t;
    }
    return t;
}

int main(int argc, char *argv[])
{
    uint64_t n = atoi(argv[1]);
    printf("%lu\n",fib(n));
    return 0;
}
