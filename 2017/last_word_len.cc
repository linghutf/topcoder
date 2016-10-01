#include <stdio.h>

#include <vector>
#include <string>

int len_last_word(const char * str)
{
    int len = 0;
    if(str==NULL) return len;
    int cnt = 0;
    char * p = (char*)str;

    while(*p!='\0')
    {
        if(*p==' ')
        {
            ++p;
            while(*p!='\0' && *p!=' ')
            {
                ++p;
                cnt++;
            }
            if(*p=='\0') return cnt;
            else
                cnt = 0;
        }else{
            ++p;
            ++cnt;
        }
    }
    return cnt;
}

void testcase()
{
    std::vector<std::string> strs={
        "",
        "the great wall",
        "world",
        "we are  you  can"
    };

    for(int i=0;i<strs.size();++i)
    {
        printf("%s:%4d\n",strs[i].c_str(),len_last_word(strs[i].c_str()));
    }
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
