#include <iostream>
#include <algorithm>
#include <functional>

#include <string>
#include <vector>

bool is_less(std::string & s1,std::string & s2)
{
    return s1.length()<s2.length();
}

int main(int argc, char *argv[])
{
    int n;
    std::cin>>n;
    std::vector<std::string> vec(n,"\0");
    for(int i=0;i<n;++i)
    {
        std::cin>>vec[i];
    }

    int type = 0;//NONE
    std::vector<std::string> tries(vec),lengths(vec);
    std::sort(tries.begin(),tries.end(),std::less<std::string>());
    if(std::equal(tries.begin(),tries.end(),vec.begin()))
    {
        type = 1;//字典序
    }

    std::sort(lengths.begin(),lengths.end(),is_less);
    if(std::equal(lengths.begin(),lengths.end(),vec.begin()))
    {
        if(type==1) type=3;//both
        else type = 2;
    }

    switch(type)
    {
        case 0:std::cout<<"none"<<std::endl;break;
        case 1:std::cout<<"lexicographically"<<std::endl;break;
        case 2:std::cout<<"lengths"<<std::endl;break;
        case 3:std::cout<<"both"<<std::endl;break;
    }

    return 0;
}
