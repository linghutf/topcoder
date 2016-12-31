/**
 *
 * 字符串数组反转
 * 例如: I am you --> You am I
 *
 * (ab)' ->b'a' -> ba
 */
#include <ctype.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void reverse_str(std::string & str)
{
    std::reverse(str.begin(),str.end());
    std::string::iterator iter_begin = str.begin();
    std::string::iterator iter_end = str.begin();
    while(iter_begin < str.end())
    {
        // 遇到空格,单词分界
        if(::isspace(*iter_begin))
        {
            ++iter_end;
            ++iter_begin;
        }
        // 找到下一个边界
        else if(iter_end == str.end() || ::isspace(*iter_end))
        {
            // 交换
            std::reverse(iter_begin,iter_end);
            // 寻找下一个
            iter_begin = iter_end+1;
            ++iter_end;
        }
        // 直到遇到单词边界
        else
        {
            ++iter_end;
        }
    }
}

void testcase()
{
    //char str[]="I am a student";
    //reverse_str(str);// ERROR
    std::string str = "I am a student";
    reverse_str(str);
    std::cout<<str<<std::endl;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
