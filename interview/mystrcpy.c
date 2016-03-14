#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrcpy(char *dst,char *src)
{
    if(dst==NULL||src==NULL)
        return NULL;
    if(dst==src)//同一个字符串
        return src;
    //不考虑内存重叠
    char *p = dst;
    const char *q=src;
    while((*p++=*q++)!='\0');

    return dst;
}

void testcase()
{
    char str[2],a[]="hello";
    strcpy(str,a);
    printf("%s\n",str);
    char s[2];
    mystrcpy(s,a);
    printf("%s\n",s);

    mystrcpy(a,a);
    printf("%s\n",s);

    char sc[2],sr[]="";
    mystrcpy(sc,sr);
    printf("%s\n",sc);
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
