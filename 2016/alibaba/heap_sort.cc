#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>

using namespace std;
//堆排序升序，原地更新
//7 6 3 5 4 1 2

//1)
//2 6 3 5 4 1 7 堆顶和最后一个元素交换
//6 5 3 2 4 1 7 调整

//2)
//1 5 3 2 4 6 7 堆顶和最后一个元素交换
//5 4 3 2 1 6 7 调整

//3)
//1 4 3 2 5 6 7 交换
//4 2 3 1 5 6 7 调整

//4)
//1 2 3 4 5 6 7 交换
//3 2 1 4 5 6 7 调整

//5)
//1 2 3 4 5 6 7 交换
//2 1 3 4 5 6 7 调整

//6)
//1 2 3 4 5 6 7 完成
int main()
{
    int a[]={7,6,3,5,4,1,2};
    int len = sizeof(a)/sizeof(a[0]);
    // 7 6 3 5 4 1 2
    // 1 4 7 5 6 3 2
    // 1 4 2 5 6 3 7
    make_heap(a,a+len,std::greater<int>());
    //pop_heap(a,a+len,std::greater<int>());

    for(int i=0;i<len;++i)
        cout<<setw(4)<<a[i];
    cout<<endl;

    return 0;
}
