/**
 * 海量数据位图排序
 * 顺便测试全局变量的栈区大小
 */
#include <iostream>
#include <bitset>
#include <climits>
#include <cstdint>

using namespace std;

//typedef unsigned int uint;
std::bitset<INT_MAX> bit;

int main(int argc, char *argv[])
{
    bit.reset();
    uint32_t a[]={751350255,234108789,134978651};
    uint32_t len =3,i;
    for(i=0;i<len;++i){
        bit.set(a[i]);
    }

    for(i=0;i<=INT_MAX;++i){
        if(bit[i])
            cout<<i<<endl;
    }
    return 0;
}
