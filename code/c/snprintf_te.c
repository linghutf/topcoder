#include <stdio.h>

int main(int argc, char *argv[])
{
    char s[2];
    snprintf(s,2,"%s",argv[1]);//'\0'占用一位,接收size-1个字符
    printf("%s\n",s);
    return 0;
}
