#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    //v作为结果存放需要预先分配空间,否则程勋运行到set_unoin插入元素时异常
    std::vector<int> v1 = {3},v2={2,5,1},v(10);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    std::vector<int>::iterator it;
    //全集
    it = std::set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    v.resize(it-v.begin());
    cout<<"全集:";
    for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
    cout<<endl;

    //交集
    v.shrink_to_fit();
    it = std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    v.resize(it-v.begin());
    cout<<"交集:";
    for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
    cout<<endl;
    //差集
    if(!v.empty()) v.shrink_to_fit();
    it = std::set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    v.resize(it-v.begin());
    cout<<"差集:";
    for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
    cout<<endl;

    //对称差集
    v.shrink_to_fit();
    it = std::set_symmetric_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    v.resize(it-v.begin());
    cout<<"对称差集:";
    for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
    cout<<endl;

    //包含
    //v.clear();
    bool isInclude= std::includes(v1.begin(),v1.end(),v2.begin(),v2.end());
    //v.resize(it-v.begin());
    //for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
    cout<<"1包含2:"<<isInclude<<endl;
    return 0;
}
