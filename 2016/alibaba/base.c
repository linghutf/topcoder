#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const char BASE[]="0123456789ABCDEF";

int idx(char c,const char *s)
{
    int m;
    int x = 0,y = strlen(s);
    while(x<=y){
        m=(x+y)>>1;
        if(s[m]==c) return m;
        else if(s[m]>c) y=m-1;
        else x=m+1;
    }
    return -1;
}

int baseToDec(char* s,int base)
{
    int n=0;
    char *p =s;
    while(*p!='\0'){
        n=base*n+idx(*p++,BASE);
    }
    return n;
}

int main()
{
    //a*b==c
    char a[]="84";
    char b[]="148";
    char c[]="B6A8";
    for(int i=11;i<=16;++i){
         if(baseToDec(a,i)*baseToDec(b,i)==baseToDec(c,i))
             printf("%d\n",i);;
    }
    return 0;;
}
