/**
 * stof自实现
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <assert.h>
#include <stdlib.h>

double stof(const char *str);


void testcase()
{
    char *s = "-123.4.5";
    assert(stof(s)==atof(s));

    char *p = "--123.4";
    assert(stof(p)==atof(p));

    char *v = "-123.4";
    //printf("%lf %lf\n",stof(v),atof(v));
    assert(stof(v)==atof(v));

    char *u = "123..4";
    //printf("%lf %lf\n",stof(u),atof(u));
    assert(stof(u)==atof(u));

    char *w = "123,4.5";
    printf("%lf %lf\n",stof(w),atof(w));
    assert(stof(w)==atof(w));
}

int main(int argc, char *argv[])
{
    testcase();

    return 0;
}

double stof(const char *str)
{
    if(str==NULL) return 0;
    size_t i=0,len = strlen(str);
    if(len==0) return 0;
    double num = 0,dot=0;
    int flag = 1;
    if(str[i]=='-'){
        flag = -1;
        i=1;
    }

    //找到小数点
    const char *p = str;
    while(*p!='.' && p<(str+len)) ++p;

    for(;i<p-str;++i){
        if(!isdigit(str[i])) goto ret;
        num = num*10+(str[i]-'0');
    }

    //小数部分
    //如123.4.5就会识别错误
    /*
    for(i=len-1;i>p-str;--i){
        if(!isdigit(str[i])) break;
        dot = dot*0.1+(str[i]-'0');
    }
    */
    for(i=p-str+1;i<len;++i){
        if(!isdigit(str[i])) break;
        dot = dot *10 +(str[i]-'0');
    }
    //dot*=0.1; //结果在第一位小数
    //dot/=10**(str+i-p+1);
    while(p!=str+i-1){
        dot/=10;
        ++p;
    }

ret:return (num+dot)*flag;
}
