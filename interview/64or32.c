/**
 * 辨别系统是64位还是32位
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%lu\n",sizeof(void*));
    /*不行的方法
    short k = ~0;
    if((unsigned short)k>65536)
        printf("64 bits.\n");
    else
        printf("32 bits.\n");

    printf("sizeof short:%lu\n",sizeof(short));
    */
    return 0;
}
