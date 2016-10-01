#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#include <stdlib.h>
#include <time.h>

#include <boost/foreach.hpp>

template<typename T,typename Comp=std::less<T> >
void heapify(T arr[],int n,int idx)
{
    Comp cmp;
    int cur = idx;
    int left = (idx<<1)+1;
    int right = (idx<<1)+2;

    // 选取合适的子节点交换
    // 选出三者最符合的元素!!!
    if(left<n && cmp(arr[left],arr[cur]))
    {
        cur = left;
    }

    if(right<n && cmp(arr[right],arr[cur]))
    {
        cur = right;
    }

    if(cur!=idx)
    {
        std::swap(arr[idx],arr[cur]);
        // 调整子节点
        heapify<T,Comp>(arr,n,cur);
    }

}

template<typename T,typename Comp=std::less<T> >
void heap_sort(T arr[],int n)
{
    // 建立优先队列
    for(int i=n/2-1;i>=0;--i)
    {
        heapify<T,Comp>(arr,n,i);
    }

    // 以此获取优先队列头部元素
    for(int i=n-1;i>=0;--i)
    {
        std::swap(arr[0],arr[i]);
        heapify<T,Comp>(arr,i,0);
    }
}

void testcase()
{
    const int N = 10;
    int arr[N];

    srand(time(NULL));

    for(int i=0;i<N;++i)
    {
        arr[i]=rand()%100;
    }
    std::cout<<"before:";
    BOOST_FOREACH(int & num,arr)
    {
        std::cout<<std::setw(4)<<num;
    }
    std::cout<<'\n';

    heap_sort<int,std::greater<int> >(arr,N);

    std::cout<<"after:";
    BOOST_FOREACH(int & num,arr)
    {
        std::cout<<std::setw(4)<<num;
    }
    std::cout<<'\n';
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
