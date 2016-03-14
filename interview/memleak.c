/**
 * 查看内存泄漏
 * gcc -g 生成调试版
 * valgrind --leak-check=full a.out
 * 查看具体泄露位置
 */

#include <stdio.h>
#include <stdlib.h>

void testcase()
{
    char *p = (char*)malloc(12);
    p[0]='l';
    p[1]='\0';
    printf("%s\n",p);
}
int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
