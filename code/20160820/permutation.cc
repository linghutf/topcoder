/**
 * 一个序列分为它和之后的两部分,
 * 一次交换自己和之后的部分的位置,就有两种
 * 递归即可得到所有可能的序列
 *
 * 递归边界:到达最后一个位置
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

void my_permu(char * str,char * another);
void permutate(char * str)
{
    my_permu(str,str);
}

// str用于保存结果
// another作为操作对象
// 二者是同一份数据
void my_permu(char * str,char * another)
{
    // 边界
    if(*another == '\0')
    {
        printf("%s\n",str);
    }
    else
    {
        // 针对每一个位置做尝试
        for(char * p = another;*p!='\0';++p)
        {
            std::swap(*p,*another);
            my_permu(str,another+1);
            std::swap(*p,*another);//回溯,返回上一状态
        }
    }
}

int main(int argc, char *argv[])
{
    char str[]="ABC";
    permutate(str);
    return 0;
}

