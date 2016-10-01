/**
 * 测试栈的空弹出是否会导致异常
 *
 */

#include <iostream>
#include <stack>

int main(int argc, char *argv[])
{
    std::stack<int> s;
    s.pop();
    return 0;
}
