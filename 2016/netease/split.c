/**
 * 字符串分割
 *
 * split可以传进多个分割符
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100 //最大分割后字符串组数

char **split(char *str,const char *sep,int *num)
{
    if(str==NULL||sep==NULL) return NULL;
    *num = 0;

    char **dst = (char**)malloc(sizeof(char*)*MAXN);
    if(dst==NULL){
        printf("malloc ERROR!\n");
        return dst;
    }

    char *p=strtok(str,sep);
    while(p!=NULL){
        dst[*num] = (char*)malloc(strlen(p)+1);
        if(dst[*num]==NULL){
            printf("malloc ERROR!\n");
            return dst;
        }
        strcpy(dst[*num],p);
        ++*num;

        //printf("%s\n",p);
        p=strtok(NULL,sep);
    }
    return dst;
}

void testcase()
{
    char s[] = "I hate you,I love you,after tomorrow,in your next day.";
    int n;
    char **p = split(s," .,",&n);
    if(p!=NULL){
        for(int i=0;i<n;++i)
        {
            printf("%s\n",p[i]);
            free(p[i]);
        }
    }
    free(p);
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
