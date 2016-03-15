#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void *mymemcpy(void *dst,const void *src,size_t sz)
{
    if(src==NULL||dst==NULL)
        return NULL;
    size_t i=0;
    byte *p=(byte*)dst,*q=(byte*)src;
    //内存没有重叠
    if(p+sz<q || q+sz<q){
        while(sz--){
            *p++=*q++;
        }
    }else{
        //内存有重叠，反向拷贝
        q+=sz-1;
        p+=sz-1;
        while(sz--)
            *--p=*--q;
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
    memcpy(v,s,sizeof(s));//为什么会成功?
    v[4]='N';
    printf("原:%s,现:%s\n",s,v);

    //内存重叠测试
    char *p=s+2,*q=s+2;
    memcpy(p,s,sizeof(s));
    printf("p:%s\n",p);

    mymemcpy(q,s,sizeof(s));
    printf("q:%s\n",q);
    return 0;
}
