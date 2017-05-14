#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    for(auto it=v.begin();it!=v.end();++it)
    {
        // 删除后，迭代器自动到被删除元素的后一个位置
        if(*it==2){v.erase(it);--it;}
    }
    for(auto it=v.begin();it!=v.end();++it)
    {
        std::cout<<*it<<'\t';
    }
    std::cout<<'\n';
    return 0;
}
