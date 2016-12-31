/**
 * 测试删除操作的迭代器行为
 */

#include <iostream>
#include <vector>

#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

int main(int argc, char *argv[])
{
    std::vector<int> vec= {100,200,300,300,300,300,500};
    for(BOOST_AUTO(it,vec.begin());it!=vec.end();++it)
    {
        if(*it==300)
        {
            // erase 删除,iter自增
            // 然后for 自增一遍
            it = vec.erase(it);
        }
    }

    BOOST_FOREACH(int & n,vec)
    {
        std::cout<<n<<std::endl;
    }

    return 0;
}
