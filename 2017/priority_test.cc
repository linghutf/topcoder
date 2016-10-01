/**
 *
 * 测试优先级队列
 *
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
int main(int argc, char *argv[])
{
    std::priority_queue<int,std::vector<int>,std::greater<int> > q;
    q.push(100);
    q.push(37);
    q.push(68);
    q.push(22);

    while(!q.empty()){
        std::cout<<q.top()<<'\n';
        q.pop();
    }
    return 0;
}
