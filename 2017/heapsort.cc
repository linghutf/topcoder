/**
 * 堆排序
 *
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#include <boost/foreach.hpp>

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l] > arr[largest])
        largest = l;
    if(r<n && arr[r] > arr[largest])
        largest = r;

    // 子节点比当前节点大
    if(largest != i)
    {
        std::swap(arr[i],arr[largest]);

        // 继续比较子节点的状态
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n)
{
    // 从下往上调整节点，从叶节点的上层开始比较
    for(int i = n/2-1;i>=0;--i)
        heapify(arr,n,i);

    // 二叉堆建立后，依次将堆顶元素移除，然后保持堆结构
    for(int i = n-1;i>=0;--i)
    {
        std::swap(arr[0],arr[i]);

        // 保持剩余元素结构
        heapify(arr,i,0);
    }
}

int main(int argc, char *argv[])
{
    int a[]={12,3,-1,7,8,11};
    int n = sizeof(a)/sizeof(a[0]);
    heapSort(a,n);

    BOOST_FOREACH(int & num,a)
    {
        std::cout<<std::setw(4)<<num;
    }
    std::cout<<'\n';
    return 0;
}
