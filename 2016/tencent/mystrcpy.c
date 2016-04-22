#include <stdio.h>
#include <string.h>

char *mystrcpy(char *dst,char *src)
{
    if(src==NULL||dst==NULL) return NULL;
    if(dst==src) return dst;
    char *p = src;
    char *q = dst;
    while(*p!='\0'){
        *q++ = *p++;
        if(q==NULL){
            *(q-1)='\0';
            return dst;
        }
    }
    *q='\0';
    return dst;
}

void testcase()
{
    char p[1];
    char str[]="123";
    mystrcpy(p,str);//内存越界，覆盖了str的值
    printf("%s\n",p);

    char *q=NULL;
    mystrcpy(q,str);
    if(q==NULL)
        printf("OK!\n");
    else
        printf("failed.\n");

    char common[4];
    mystrcpy(common,str);
    printf("%s\n",common);

}

int main()
{/*
    char p[1];
    char str[]="123";
    strcpy(p,str);//越界了
    printf("%s\n",p);
*/
    //mystrcpy
    //testcase();
    char q[10];
    char str[]="123";
    mystrcpy(q,str);
    printf("[mystrcpy]:%s\n",q);
    return 0;
}
