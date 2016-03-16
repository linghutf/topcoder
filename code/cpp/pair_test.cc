/**
 * 测试pair和hashmap可不可以使用char *作为key,value
 *
 * 结论: pair map 可以
 *       unordered_map 不可以,需要自己实现hash函数
 */
#include <iostream>
#include <utility>
#include <unordered_map>
#include <map>
using namespace std;

template<>
struct std::hash<std::pair<char*,char*>>{

};

int main(int argc, char *argv[])
{
    std::pair<char *,char*> p;
    //p.first = "haha";
    //p.second= "hallo";
    //std::map<std::pair<char*,char*>,int> t;
    //std::unordered_map<std::pair<int,int>,int> test;
    //std::unordered_map<std::pair<char*,char*>,int> test;

    return 0;
}
