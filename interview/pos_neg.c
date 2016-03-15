/**求二进制的反转
 *
 */

#include <stdio.h>
#include <stdlib.h>

//#include "bformat.h"

void bprint(int n);

unsigned int bit_reverse(unsigned int n)
{
    n = ((n>>1)&0x55555555)|((n<<1)&0xaaaaaaaa);//0101 1010
    n = ((n>>2)&0x33333333)|((n<<2)&0xcccccccc);//0011 1100
    n = ((n>>4)&0x0f0f0f0f)|((n<<4)&0xf0f0f0f0);//00001111 11110000
    n = ((n>>8)&0x00ff00ff)|((n<<8)&0xff00ff00);//0000000011111111
    n = ((n>>16)&0x0000ffff)|((n<<16)&0xffff0000);
    return n;
}

int main(int argc, char *argv[])
{
    //unsigned int n = atoi(argv[1]);
    unsigned int n = 0xffff000;
    printf("n:%x\n",n);
    //bprint(n);
    printf("\nrev:");
    unsigned int k = bit_reverse(n);
    //bprint(k);
    printf("\n%x\n",k);
    return 0;
}

void bprint(int n)
{
    while(n){
        (n&1)?printf("1"):printf("0");
        n>>=1;
    }
}
