#include <stdio.h>
#include <stdlib.h>

void* mymemcpy(void* dst,void* src,size_t n)
{
    if(dst==NULL||src==NULL) return NULL;
    if(dst==src) return dst;
    char *p=(char*)src;
    char *q=(char*)dst;
    for(size_t i = 0;i<n;++i)
        *(q+i)=*(p+i);
    return dst;
}

void testcase()
{
    char str[]="1234";
    char p[5];
    mymemcpy(p,str,5);
    printf("%s\n",p);
}

int main()
{
    testcase();
    return 0;
}
