/**
 * 字符串转化成整数
 */

#include <stdio.h>

int myatoi(const char * str)
{
    int num = 0;
    bool isNeg = false;
    if(str==NULL) return num;

    char * p = (char*)str;

    if(*p!='\0')
    {
        if(*p=='-')
        {
            // 错误
            if(*(p+1)>='9' || *(p+1)<='0')
            {
                return num;
            }
            else
            {
                isNeg = true;
                ++p;//下一位置
            }
        }
        // 计算部分
        while(*p!='\0')
        {
            if(*p<='9' && *p>='0')
            {
                num=10*num+(*p-'0');
                ++p;
            }
            else
            {
                break;
            }
        }
    }
    return isNeg?-num:num;
}

void testcase()
{
    char t1[]="-12345";
    char t2[]="9987";
    char t3[]="";
    char t4[]="--1234";
    char t5[]="123.4";
    printf("t1:%d\n",myatoi(t1));
    printf("t2:%d\n",myatoi(t2));
    printf("t3:%d\n",myatoi(t3));
    printf("t4:%d\n",myatoi(t4));
    printf("t5:%d\n",myatoi(t5));
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
