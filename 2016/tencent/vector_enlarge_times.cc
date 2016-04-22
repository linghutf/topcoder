/**
 * vector增长倍数
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int len = 4;
    vector<int> v(len,0);
    for(int i=0;i<len;++i){
        cout<<"capacity:"<<v.capacity()<<",size:"<<v.size()<<",addr:"<<&v<<endl;
        v[i]=i+1;
    }
    for(int i=0;i<len;++i){
        cout<<"capacity:"<<v.capacity()<<",size:"<<v.size()<<",addr:"<<&v<<endl;
        v.push_back(i+1+len);
    }
    return 0;
}
