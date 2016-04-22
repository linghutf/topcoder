#include <stdio.h>
#include <stdint.h>
#include <string.h>


struct Packet{
    uint8_t magic;
    uint8_t opcode;
};

int main()
{
    struct Packet p;
    char buf[4];
    buf[0]=0x80;
    buf[1]=0x32;

    memcpy(&(p.magic),buf,1);
    memcpy(&(p.opcode),buf+1,1);
    printf("%d,%d\n",p.magic,p.opcode);

    return 0;
}
