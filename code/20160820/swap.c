#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(const void * a,const void * b)
{
    if(a==NULL||b==NULL)
    {
        return;
    }
    void * p = (void *)a;//擦除了const属性?
    void * q = (void *)b;
    void *tmp = (void *)malloc(sizeof(*a));
    memcpy(tmp,p,sizeof(*a));
    memcpy(p,q,sizeof(*b));
    memcpy(q,tmp,sizeof(*tmp));
    free(tmp);
}

int main(int argc, char *argv[])
{
    int a = 10, b = 12;
    swap(&a,&b);
    printf("%d,%d\n",a,b);

    char c = 'a',d='z';
    swap(&c,&d);
    printf("%c,%c\n",c,d);

    return 0;
}
