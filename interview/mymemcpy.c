#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void *mymemcpy(void *dst,void *src,size_t sz)
{
    size_t i=0;
    byte *p=(byte*)dst,*q=(byte*)src;
    while(i<sz){
        *(p+i) = *(q+i);
        ++i;
    }
    return p;
}

int main(int argc, char *argv[])
{
    char s[]="hello";
    char t[10];
    mymemcpy(t,s,sizeof(s));
    printf("%s\n",t);

    char v[2];
    memcpy(v,s,sizeof(s));
    printf("%s\n",v);
    return 0;
}
