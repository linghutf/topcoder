/**
 * 测试C++11 hash函数
 */
#include <iostream>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    std:hash<char> chash;
    cout<<chash('a')<<endl;

    std::hash<int> ihash;
    cout<<ihash(12)<<endl;
    return 0;
}
