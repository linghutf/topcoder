/**
 *
 * 组合,从n中选取m个,包含相同元素
 * 分解为两个子问题:
 * 1. 包含第一个元素 + 剩余的C(m-1,n-1)
 * 2. 不含第一个元素 + 剩余的C(m,n-1)
 */

#include <stdio.h>
#include <string.h>

#include <string>
#include <algorithm>

void permutate(char * str,size_t m)
{
    int n = strlen(str);
    if(str==NULL||m==0)
    {
        return;
    }
    if(m>n)
    {
        m = n;
    }

    std::string out;
    permutate(str,m,out);
}

void permutate(char * str,int m,std::string & out)
{
    int len = strlen(str);
    // 边界条件
    if(out.length()==len)
    {
        printf("%s\n",out.c_str());
    }
    else
    {
        for(int i = 0;i<m;++i)
        {
            out.push_back(*str);
            permutate(str+1,out);
            out.pop_back();
        }
    }
}
