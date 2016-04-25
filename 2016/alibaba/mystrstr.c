#include <stdio.h>
#include <string.h>

//比较到'\0'返回
int mystrncmp(char* a,char* b,size_t n)
{
    //if(a==NULL||b==NULL) return 0;
/*
    char *p=a,*q=b;
    while(*p!='\0'&& *q!='\0'){
        if(p-a==n) break;
        if(*p!=*q){
            return *p-*q;
        }
        p++;
        q++;
    }
*/
    if(n<=0) return 0;
    char *p=a,*q=b;
    while(--n && *p && *q && *p==*q){
        p++;
        q++;
    }
    return *p-*q;
}

char* mystrstr(char* str,const char* sub)
{
    if(str==NULL) return NULL;
    if(sub==NULL) return str;
    char *p = str;
    int len = strlen(sub);
    while(*p!='\0' && mystrncmp(p,sub,len)!=0) ++p;
    if(*p=='\0')
        return NULL;
    else
        return p;
}

void testcase(char* str,char* sub)
{
    char *p=mystrstr(str,sub);
    if(p==NULL)
        printf("null ok.\n");
    else
        printf("%s\n",p);

}

void testcase_strncmp()
{
    char str[]="1234";
    char str2[]="123456";
    int len1 = strlen(str);
    int len2 = strlen(str2);
    printf("%d,%d\n",str2[len1],mystrncmp(str,str2,len2));
}

int main(int argc,char* argv[])
{
    //char str[]="1234";
    testcase(argv[1],argv[2]);
    testcase_strncmp();

    char str[]="";
    printf("0 len:%d,%d\n",str[0],strncmp(str,"1234",4));
    return 0;
}
