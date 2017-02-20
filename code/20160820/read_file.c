/**
 * 测试read/wirte写标准输入输出
 * 测试未通过
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[16]={0};
    ssize_t cnt = read(stdin,str,16);
    write(stdout,&cnt,sizeof(cnt));
    write(stdout,str,strlen(str));
    return 0;
}
