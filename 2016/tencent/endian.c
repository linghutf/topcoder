#include <stdio.h>
#include <stdint.h>

typedef union{
    int32_t a;
    struct{
        int16_t b;
        int16_t c;
    };
}endian;

endian a;

int main(int argc, char *argv[])
{
    a.a = 0x20150810;
    printf("[%p]%x,%x\n",&a,a.b,a.c);
    return 0;
}
