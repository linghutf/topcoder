/**判断机器大小端
 *
 * 大端机器:数位高的数据存储在低地址位上
 * 小端机器:数位低的数据存储在高地址位上
 * 例如: 地址 0x 01 02 03 04
 *   int数据1    00 00 00 01 大端
 *               01 00 00 00 小端
 */
#include <stdio.h>
#include <stdlib.h>

int a = 0x01020304;

void testByObjDump()
{
    char *p = (char*)&a;
    /**
     * 打印a的地址,然后在编译的二进制文件中查找
     * objdump -s a.out
     * section.data全局数据区的字节顺寻
     * 全局变量区是栈区，地址位从高到低
     * 所以如果是大端则是01020304
     * 小端是04030201
     */
    printf("ret=%d\n&a=%p\n",*p,&a);
}

void testByUnion()
{
    typedef union{
        int a;
        char b;//由于共用一块内存区域
    }Endian;

    Endian endian;
    endian.a=1;
    /**
     * a=0x00 00 00 01
     * 打印1个字节,现在有4个字节
     * 局部变量在栈区，地位申请从高到低
     * 如果是大端,从高位打印,则打印0
     * 如果是小端,从低位打印,则打印1
     */
    printf("ret=%d\n",endian.b);

    //堆测试
    Endian *p = (Endian *)malloc(sizeof(Endian));
    if(p==NULL) return;
    p->a = 1;
    printf("ret=%d\n",p->b);
    free(p);
}

void testByShort()
{
    int x[]={1,2};
    printf("%x\n",*(int*)x);
}
int main(int argc, char *argv[])
{
    /*
    short a[]={1,2};
    printf("%x:[int]%d,[short]%d\n",(int)(a),sizeof(int),sizeof(short));
    */
    testByObjDump();
    testByUnion();
    testByShort();
    return 0;
}
