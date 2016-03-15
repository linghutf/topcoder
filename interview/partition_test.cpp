#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

//前开后闭区间
void QuickSort(int *start,int *end)
{
    if(start==end-1)
        return;
    auto index = std::partition(start,end,[=](int n){return n<=(*start);});
    if(index>=start)
        QuickSort(start,index);//[start,index)
    if(index<=end)
        QuickSort(index,end);//[index,end)
}

void testcase()
{
    int a[]={-9,12,4,2,3,-1,7,9,79,21,2};
    int len  = sizeof(a)/sizeof(a[0]);
    QuickSort(a,a+len);
    std::for_each(a,a+len,[](int i){cout<<i<<'\t';});
    cout<<endl;
}

void testcase2()
{
    int a[]={-9,12,4,2,3,-1,7,9,79,21,2};
    int len = sizeof(a)/sizeof(a[0]);
    //bool func = [](int i)
    int flag = a[0];
    auto index1 = std::partition(a,a+len/2,[=](int i){return i<=flag;});
    auto index2 = std::partition(a+len/2,a+len,[=](int i){return i>=flag;});

    std::for_each(a,a+len,[](int i){cout<<i<<'\t';});
    cout<<endl;
    cout<<"index:"<<*index1<<","<<*index2<<endl;
}
int main(int argc, char *argv[])
{
    /*
    int a[]={1,2,3,4};
    std::partition(a,a+4,[](int i){return (i&0x1)==0;});
    std::for_each(a,a+4,[](int i){cout<<i<<endl;});
    */
    testcase2();
    return 0;
}
