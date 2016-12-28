#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

template<class Comp>
void bublle_sort(int * a ,int len,Comp && cmp=std::greater<int>())
{
    if(a==NULL||len<=0) return;
    for(int i=0;i<len;++i)
    {
        for(int j=0;j<len-1-i;++j)
        {
            if(cmp(a[j],a[j+1]))
            {
                std::swap(a[j],a[j+1]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 engine(seed1);

    const int len = 10;
    int arr[len];
    std::generate(arr,arr+len,[&engine](){return engine()%100+1;});

    std::for_each(arr,arr+len,[](const int num){std::cout<<'\t'<<num;});
    std::cout<<'\n';

    bublle_sort<std::greater<int>>(arr,len);

    std::for_each(arr,arr+len,[](const int num){std::cout<<'\t'<<num;});
    std::cout<<'\n';

    bublle_sort<std::less<int>>(arr,len,std::less<int>());
    std::for_each(arr,arr+len,[](const int num){std::cout<<'\t'<<num;});
    std::cout<<'\n';

    return 0;
}
