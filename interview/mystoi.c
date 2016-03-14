/**
 * atoi自实现
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <assert.h>
#include <stdlib.h>

int stoi(const char *str);

void testcase()
{
    /*
    char *s=NULL;//atoi产生异常
    printf("%d\n",atoi(s));
    assert(stoi(s)==atoi(s));
    */

    char *p="";
    assert(stoi(p)==atoi(p));

    char *t="--123";
    assert(stoi(t)==atoi(t));

    char *v="-123";
    //printf("%d %d\n",stoi(v),atoi(v));
    assert(stoi(v)==atoi(v));

    char *u="-0";
    assert(stoi(u)==atoi(u));

}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}

int stoi(const char *str)
{
    if(str==NULL)
        return 0;
    size_t i=0,len=strlen(str);
    if(len==0)
        return 0;
    int num = 0;
    int flag = 1;
    if(str[0]=='-'){
        flag = -1;
        i=1;
    }

    for(;i<len;++i){
        if(!isdigit(str[i])) break;
        num = num*10+(str[i]-'0');
    }
    return num*flag;
}
