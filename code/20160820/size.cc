/**
 * 64bit数据宽度
 *
 */

#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    char str[][4]={{0},{1234},{567},{8}};
    char (*p)[4];
    p = str;
    char * q = p[1];
    printf("size:%2lu,int:%lu,pointer:%2lu\n",sizeof(str),sizeof(int),sizeof(q));
    assert(q[2]==3);

    return 0;
}
