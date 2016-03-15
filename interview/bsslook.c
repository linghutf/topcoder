/**
 * BSS段查看
 * static变量的未初始化部分
 * 已经初始化的在.data数据中
 * readelf -S main.o
 * objdump -t main.o
 */

#include <stdio.h>

static int g;//4个字节
static short int h;//2个字节

int main(int argc, char *argv[])
{

    return 0;
}
