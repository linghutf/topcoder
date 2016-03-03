#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void min_heap_test();
void max_heap_test();

int main(int argc, char *argv[])
{
    vector<int> v={10,-5,2,3,90,78,21},v2(v);
    //默认是大顶堆
    std::make_heap(v.begin(),v.end());
    std::pop_heap(v.begin(),v.end());
    cout<<v.back()<<endl;
    v.pop_back();
    //不需要再用make_heap维持堆
    std::pop_heap(v.begin(),v.end());
    cout<<v.back()<<endl;
    v.pop_back();

    //小顶堆
    std::make_heap(v2.begin(),v2.end(),[](int a,int b){return a>b;});
    std::pop_heap(v2.begin(),v2.end());
    cout<<v2.back()<<endl;
    v2.pop_back();
    std::pop_heap(v2.begin(),v2.end());
    cout<<v2.back()<<endl;
    v2.pop_back();

    //push_heap
    //插入堆将数据放在容器末尾
    v.push_back(12);
    std::push_heap(v.begin(),v.end());
    //sort_heap，堆排序
    std::sort_heap(v.begin(),v.end());
    std::for_each(v.begin(),v.end(),[](auto i){cout<<i<<'\t';});
    cout<<endl;

    cout<<"Min_Heap Test:"<<endl;
    min_heap_test();
    cout<<"Max_Heap Test:"<<endl;
    max_heap_test();
    return 0;
}

void min_heap_test()
{
    vector<int> v={98,67,43,43,-2,13,15};
    std::make_heap(v.begin(),v.end(),[](int a,int b){return a>b;});
    while(v.size()>0){
        std::pop_heap(v.begin(),v.end());
        cout<<v.back()<<endl;
        v.pop_back();
        //每次改变堆都要重新维持堆
        std::make_heap(v.begin(),v.end(),[](int a,int b){return a>b;});
    }

    cout<<"Min Heap Insert:"<<endl;
    for(int i=10;i>0;--i){
        v.push_back(i);
        std::push_heap(v.begin(),v.end());//需要重新维持堆结构
    }

    std::make_heap(v.begin(),v.end(),[](int a,int b){return a>b;});
    while(v.size()>0){
        std::pop_heap(v.begin(),v.end());
        cout<<v.back()<<endl;
        v.pop_back();
        std::make_heap(v.begin(),v.end(),[](int a,int b){return a>b;});
    }

}

void max_heap_test()
{
    vector<int> v={98,67,43,43,-2,13,15};
    std::make_heap(v.begin(),v.end());
    while(v.size()>0){
        std::pop_heap(v.begin(),v.end());
        cout<<v.back()<<endl;
        v.pop_back();
        //大顶堆不用维持堆结构
        //std::make_heap(v.begin(),v.end(),[](int a,int b){return a>b;});
    }

    //heap insert
    cout<<"Max Heap Insert:"<<endl;
    for(int i=0;i<10;++i){
        v.push_back(i);
        std::push_heap(v.begin(),v.end());
    }

    while(v.size()>0){
        std::pop_heap(v.begin(),v.end());
        cout<<v.back()<<endl;
        v.pop_back();
        //大顶堆不用维持堆结构
        //std::make_heap(v.begin(),v.end(),[](int a,int b){return a>b;});
    }

}
