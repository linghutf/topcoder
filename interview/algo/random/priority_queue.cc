#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    std::priority_queue<int,std::vector<int>,std::greater<int>> q;
    q.push(3);
    q.push(1);
    q.push(4);
    q.push(2);
    q.push(5);
    q.push(8);
    q.push(11);
    q.push(13);

    //for_each(q.begin());
    while(!q.empty()){
        cout<<q.top()<<endl;
        q.pop();
    }
    return 0;
}
