#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void get_next(const char * str,int * next)
{
    if(next==NULL||str==NULL) return;
    int i=0,j=-1;
    next[i]=j;
    int len = strlen(str);
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            ++j;
            ++i;
            if(str[i]==str[j])
            {
                next[i]=next[j];
            }
            else
            {
                next[i]=j;
            }
        }else
        {
            j=next[j];
        }
    }
}

int kmp(const char * sub,const char * str)
{
    if(str==NULL||sub==NULL) return -1;

    int sub_len = strlen(sub);
    int str_len = strlen(str);

    if(sub_len==0) return 0;
    if(str_len==0) return -1;

    int * next = (int*)malloc(sizeof(int)*sub_len);
    get_next(sub,next);
    for(int i=0;i<sub_len+1;++i)
    {
        printf("%3d",next[i]);
    }
    printf("\n");
    int i=0,j=0;
    while(i<str_len)
    {
        if(j==-1||sub[j]==str[i])
        {
            ++j;
            ++i;
            // found
            if(j==sub_len)
            {
                return i-j;
            }
        }else{
            // back
            j = next[j];
        }
    }
    free(next);
    return -1;

}


int main(int argc, char *argv[])
{
    printf("%s --- %s : %d\n",argv[1],argv[2],kmp(argv[2],argv[1]));
    return 0;
}
