#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>

int len_of_last_word(const char * str)
{
    char * p =(char*)str;
    char * q =(char*)str;
    while(*p!='\0')
    {
        if(ispunct(*p)||isspace(*p)) // 单词分隔
        {
            q = p+1;
        }
        ++p;
    }
    return p-q;
}


void test()
{
    std::vector<std::string> strs={
        " I lowe China.",
        "I hate this",
        "Beijing",
        ""
    };

    //std::vector<std::string>::iterator it = strs.begin();
    for(auto it=strs.begin();it!=strs.end();++it)
    {
        std::cout<<*it<<":"<<len_of_last_word(it->c_str())<<std::endl;
    }
}

int main(int argc, char *argv[])
{
    test();

    return 0;
}
