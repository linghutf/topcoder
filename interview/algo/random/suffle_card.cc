/**
 * 扑克牌洗牌
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <chrono>


using namespace std;

//改变位置的随机
void random_suf(int a[],int len,unsigned seed)
{
    std::default_random_engine engine(seed);
    int i=0,pos;
    /*
     * 错误，随机到的位次次数不一样
     * 使用fisher-yates方法
     */
    for(i=0;i<len;++i)
    {
        pos = i+engine()%(len-i);
        std::swap(a[pos],a[i]);
    }
}

int main(int argc, char *argv[])
{
    int m = 54;
    int a[54]={0};

    for(int i=1;i<=m;++i)
        a[i-1]=i;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //std::mt19937 engine(seed);
    //std::ranlux24 engine(seed); too slow
    //std::minstd_rand0 engine(seed);
    //std::default_random_engine engine(seed);

    //way 1.
    //std::shuffle(a,a+m,std::mt19937(seed));
    //way 2
    random_suf(a,m,seed);
    std::for_each(a,a+m,[](int n){cout<<setw(3)<<n;});
    cout<<endl;

    return 0;
}
