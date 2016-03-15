#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>

#include <boost/dynamic_bitset.hpp>
using namespace std;


void testcase()
{
    unsigned int a[]={751350255,650819789,134267589};
    unsigned int count = 3;
    const int N=INT_MAX;
    //std::bitset<N> bit;//大约250MB内存使用，超出了栈的大小，因此异常
    //替代方法boost::dynamicbitset
    boost::dynamic_bitset<unsigned int> bit(N,0);
    //bit.reset();
    unsigned int i,j;
    for(i=0;i<count;++i){
        bit.set(a[i],1);
    }

    for(i=0;i<=N;++i){
        if(bit[i]==1){
            cout<<i<<endl;
            j++;
        }
        if(j==count) break;//后面的不搜索了
    }
}

int main(int argc, char *argv[])
{
    testcase();
    bitset<16> v;
    v.reset();
    return 0;
}
