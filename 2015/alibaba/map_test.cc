/**
 * 测试[]元素符会不会添加元素到map中
 * []会在没有匹配的时候增加新值
 */

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    map<int,int> m;
    unordered_map<int,int> um;
    cout<<m[0]<<","<<m.size()<<endl;
    cout<<um[0]<<","<<um.size()<<endl;

    return 0;
}
