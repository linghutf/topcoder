/**
 * 从100万个数中找到最大的10个数
 * 使用size为10的最小堆
 *
 * 测试使用1000个在(0-10000)数字，找到最大的20个数
 * 使用sort验证正确性
 * 并且使用bitmap验证
 * 结论:思路正确
 */
#include <iostream>
#include <algorithm>
#include <functional>

#include <vector>
#include <bitset>//验证

#include <cstdlib>
#include <ctime>

using namespace std;

#define K 20
#define UP 10000

//使用map验证
std::bitset<UP> BITMAP;
//产生随机数
void generate_N(int a[],int nums)
{
    srand(time(NULL));
    for(int i=0;i<nums;++i)
        a[i]=rand()%UP;
}

//验证正确性
void check_correct(int a[],int len)
{
    std::sort(a,a+len,std::greater<int>());//默认升序,需要传递仿函数降序排列
    cout<<"Sort:";
    std::for_each(a,a+K,[](int n){cout<<n<<'\t';});
    cout<<endl;
    //反转
    for(int i=0;i<K;++i)
        BITMAP.set(a[i],0);
}

//topk解法
void TopK(int a[],int len)
{
    //std::begin只能在定义数组的范围内使用，因为数组传递不包括边界信息
    //所以对a不能使用而对b可以
    int b[K]={0};
    std::copy(a,a+K,std::begin(b));
    std::make_heap(std::begin(b),std::end(b),std::greater<int>());//min heap
    for(int i=K;i<len;++i){
        if(a[i]>*std::begin(b)){//遇到比堆顶大的元素,
            std::pop_heap(std::begin(b),std::end(b),std::greater<int>());//丢掉堆顶
            //在尾部添加新元素
            *(b+K-1) = a[i];
            std::push_heap(std::begin(b),std::end(b),std::greater<int>());//维持堆结构
        }
        //if (std::pop_heap(std::begin(b),std::end(b)))
    }

    //插入bitmap
    for(auto it = std::begin(b);it!=std::end(b);++it)
    {
        BITMAP.set(*it);
    }

    cout<<"TopK:";
    std::for_each(std::begin(b),std::end(b),[](int n){cout<<n<<'\t';});
    cout<<endl;
}

//测试用例
void testcase()
{
    int nums = 1000;
    int a[1000];
    generate_N(a,nums);

    TopK(a,nums);

    check_correct(a,nums);

    //验证是否全0
    if(BITMAP.none())
        cout<<"CORRECT!"<<endl;
}
//测试最小堆
void testcase2()
{
    std::vector<int> a={1,4,3,5};
    std::make_heap(std::begin(a),std::end(a),std::greater<int>());

    cout<<*std::begin(a)<<endl;
    std::pop_heap(std::begin(a),std::end(a),std::greater<int>());
    //drop
    a.pop_back();
    //添加元素
    a.push_back(2);
    std::push_heap(std::begin(a),std::end(a),std::greater<int>());
    cout<<*std::begin(a)<<endl;
}
int main(int argc, char *argv[])
{
    testcase();
    //testcase2();
    return 0;
}
