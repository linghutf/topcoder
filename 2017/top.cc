#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

int main(int argc, char *argv[])
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 g(seed);

    int num = 100;
    int topk=10;
    std::vector<int> v(topk,0);
    std::vector<int> src(num,0);
    for(int i=0;i<num;++i)
    {
        src[i]=(g()%1000+1); // 不能使用push_back
    }

    // top k
    for(int i=0;i<topk;++i)
    {
        v[i] = src[i];
    }
    // 大顶堆
    auto funp = std::less<int>();
    std::make_heap(v.begin(),v.end(),funp);
    for(int i=topk;i<num;++i)
    {
        if(v[0]>src[i])
        {
            std::pop_heap(v.begin(),v.end(),funp);
            v.pop_back();
            v.push_back(src[i]);
            //v[topk-1] = src[i];
            std::make_heap(v.begin(),v.end(),funp);

            //std::push_heap(v.begin(),v.end(),std::less<int>());
        }
    }

    // print
    std::cout<<"top "<<topk<<":\n";
    std::for_each(v.begin(),v.end(),[](int & n){std::cout<<n<<'\t';});
    std::cout<<std::endl;

    // verify
    std::cout<<"top "<<topk<<":\n";
    std::sort(src.begin(),src.end(),funp);
    std::for_each(src.begin(),src.end(),[](int & n){std::cout<<n<<'\t';});
    std::cout<<std::endl;

    return 0;
}
