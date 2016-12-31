/**
 * C++11 依然支持make_pair带模板参数
 */

#include <iostream>
#include <string>
#include <algorithm>

void test()
{
    std::make_pair<int,std::string>(12,"hello");
}

void test_cpp11()
{
    std::make_pair(12,"hello");
}

int main(int argc, char *argv[])
{
    test();
    test_cpp11();

    return 0;
}
