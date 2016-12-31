/**
 * 简单的快排
 */

#include <iostream>
#include <algorithm>
#include <functional>

#include <boost/foreach.hpp>

void mysort(int * b,int * e)
{
    size_t sz = std::distance(b,e);

    if(sz>1)
    {
        auto p = std::prev(e);
        std::swap(*std::next(b,sz/2),*p);

        auto q = std::partition(b,p,std::bind1st(std::less<int>(),*p));
        std::swap(*q,*p);
        mysort(b,q);
        mysort(std::next(q),e);
    }
}

int main(int argc, char *argv[])
{
    int a[]={7,-4,3};
    int len = sizeof(a)/sizeof(a[0]);
    mysort(a,a+len);

    BOOST_FOREACH(int & n,a)
    {
        std::cout<<n<<std::endl;
    }
    return 0;
}
