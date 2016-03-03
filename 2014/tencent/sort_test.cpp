#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v={10,12,-8,4,2,1,3,78};
    cout<<"升序排列:";
    std::sort(v.begin(),v.end());
    std::for_each(v.begin(),v.end(),[](auto i){cout<<i<<'\t';});
    cout<<endl;

    cout<<"降序排列:";
    std::sort(v.begin(),v.end(),[](auto a,auto b){return a>b;});
    std::for_each(v.begin(),v.end(),[](auto i){cout<<i<<'\t';});
    cout<<endl;

    return 0;
}
