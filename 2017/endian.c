#include <stdio.h>

typedef union{
    char c;
    int n;
}Endian;

typedef unsigned char byte;

typedef union{
    struct{
        byte bit1:1;
        byte bit2:1;
        byte bit3:1;
        byte bit4:1;
        byte bit5:1;
        byte bit6:1;
        byte bit7:1;
        byte bit8:1;
    }u;
    byte s;
}endian;

int main(int argc, char *argv[])
{
    /*
    Endian e;
    e.n=0x1234;
    printf("size:%lu,low:%c\n",sizeof(int),e.c);
    */
    endian c;
    c.s = 1;
    /*
    c.u.bit1 = 0x1;
    c.u.bit2 = 0x2;
    c.u.bit3 = 0x3;
    c.u.bit4 = 0x4;
    c.u.bit5 = 0x5;
    c.u.bit6 = 0x6;
    c.u.bit7 = 0x7;
    c.u.bit8 = 0x8;
    */
    printf("low:%d,high:%d\n",c.u.bit1,c.u.bit8);

    return 0;
}
