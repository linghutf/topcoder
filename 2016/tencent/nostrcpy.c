#include <stdio.h>

char *mystrcpy(char *dst,char *src)
{
    if(dst==NULL||src==NULL) return NULL;
    if(dst==src) return dst;
    char *q=dst;
    char *p=src;
    while((*q++=*p++)!='\0');
    return dst;
}

void testcase()
{
    char p[1];
    char str[]="hello,world!";
    mystrcpy(p,str);
    printf("%s\n",p);

    char q[10];
    mystrcpy(q,str);
    printf("%s\n",q);
}

int main()
{
    testcase();
    return 0;
}
