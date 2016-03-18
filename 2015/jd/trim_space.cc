/**
 * 将ASCII字符串去掉开头结尾的空格
 * 中间多个空格合并到一个
 */

#include <cstdio>
#include <cstring>
#include <cctype>

void FormatString(char *str,int len)
{
    if(str==NULL||len<=0) return;
    char *p = str;
    while(std::isspace(*p)) ++p;
    char *q=str;
    while(q<str+(str+len-p)){
        if(std::isspace(*p)){
            *q++ = ' ';
            while(std::isspace(*p++));
        }
        if(p>=str+len) break;
        *q++=*p++;
    }
}

int main(int argc, char *argv[])
{
    char s[]="  I am   a     little boy.    ";

    FormatString(s,strlen(s));
    printf("|%s|\n",s);

    return 0;
}
