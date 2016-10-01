#include <math.h>
#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <bitset>
#include <algorithm>

const int MAX_NUM = (1<<28);

static std::bitset<MAX_NUM> g_flags;

void init(int min,int max)
{
    if(max<2) return;

    g_flags.set();

    g_flags.set(2);
    int i,j;
    for(i=2;i<=sqrt(max);++i)
    {
        if(!g_flags[i]) continue;
        for(j=i<<1;j<=max;j+=i)
        {
            g_flags.reset(j);
        }
    }
}

void testcase()
{
    for(int i=2;i<=100;++i)
    {
        if(g_flags[i])
            std::cout<<std::setw(3)<<i;
    }
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    struct timeval t,e;
    gettimeofday(&t,NULL);
    init(2,10000000);
    gettimeofday(&e,NULL);
    std::cout<<"time:"<<((e.tv_sec-t.tv_sec)*1000+(e.tv_usec-t.tv_usec)/1000)<<" ms."<<std::endl;

    testcase();
    return 0;
}
