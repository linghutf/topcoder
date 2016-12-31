/**
 * top k 问题
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include <boost/foreach.hpp>

template<typename T,typename Pred>
void top_k(std::vector<T> & in,std::vector<T> & out,size_t n)
{
    if(in.empty()||n==0) return;
    Pred pred;

    out.resize(n);

    if(in.size()<=n)
    {
        out = in;
        std::make_heap(out.begin(),out.end(),pred);
    }
    else
    {
        std::copy(in.begin(),in.begin()+n,out.begin());
        std::make_heap(out.begin(),out.end(),pred);
        for(int i = n;i<in.size();++i)
        {
            // 压入堆
            if(pred(in[i],*out.begin()))
            {
                std::pop_heap(out.begin(),out.end(),pred);
                out.pop_back();
                out.push_back(in[i]);
                std::push_heap(out.begin(),out.end(),pred);
            }
        }
    }
}

// --- test ---

void testcase()
{
    std::vector<int> v = {3,1,7,6,2,4,7,8};
    int n = 5;
    std::vector<int> out;
    // 最大的k个数
    top_k<int,std::greater<int> >(v,out,n);

    BOOST_FOREACH(int & num,out)
    {
        std::cout<<num<<std::endl;
    }
}

int main(int argc, char *argv[])
{
    testcase();

    return 0;
}
