/**
 * memcpy以字节为单位复制
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_memmove()
{
    int len = 5;
    int *p = (int*)malloc(sizeof(int)*(len+3));

    int i;
    for(i=0;i<len;++i){
        p[i]=i+1;
    }
    int *q;
    memmove(p+3,p,sizeof(int)*len);
    q=p+3;
    //p : 1 2 3 1 2
    //q :       1 2 3 4 5
    //可以看出，memmove是从后往前复制,反向拷贝
    printf("memmove:\n");
    for(i=0;i<len;++i){
        printf("p:%d,q:%d\n",p[i],q[i]);
    }
    free(p);
}

void test_memcpy()
{
    int len = 5;
    int *p = (int*)malloc(sizeof(int)*(len+3));

    int i;
    for(i=0;i<len;++i){
        p[i]=i+1;
    }
    int *q;
    memcpy(p+3,p,sizeof(int)*len);
    q=p+3;
    //p : 1 2 3 1 2
    //q :       1 2 3 1 2
    //可以看出，memcpy是从前往后复制，正向拷贝
    printf("memcpy:\n");
    for(i=0;i<len;++i){
        printf("p:%d,q:%d\n",p[i],q[i]);
    }
    free(p);

}
int main()
{
    test_memmove();

    test_memcpy();

    return 0;
}
