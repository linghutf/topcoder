/**
 *
 * 3个骰子的点数分布
 *
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <boost/foreach.hpp>

typedef std::unordered_map<int,int> Map;

void dfs(int sum,int n,Map & count)
{
    if(n==3){
        count[sum]++;

    }else{
        for(int i=1;i<=6;++i){
            dfs(sum+i,n+1,count);
        }
    }
}

int main(int argc, char *argv[])
{
    Map count;
    dfs(0,0,count);
    BOOST_FOREACH(auto & pair,count)
    {
        std::cout<<pair.first<<":"<<std::setw(4)<<pair.second<<std::endl;
    }
    return 0;
}
