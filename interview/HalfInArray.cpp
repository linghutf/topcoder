#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T> T halfAppearInArray(const T *a,size_t sz)
{
    if(a==NULL||sz<=0)
        throw std::runtime_error("container is empty or parameter error.");
    std::vector<T> vec(a,a+sz);
    auto p=vec.end(),q=p;
    //std::vector<T>::reverse_iterator q;
    int leave = vec.size()%2==0?2:1;
    T r;
    //int ret;
    while(vec.size()>leave){
        p = vec.end()-1;
        for(q=vec.end()-2;q!=vec.begin()-1;--q){
            if(*p != *q){
                vec.erase(p);
                vec.erase(q);
                break;
            }
        }
        r = vec.front();//只对整形有效
        std::for_each(vec.begin(),vec.end(),[&r](auto &u){r^=u;});//异或表示不同
        if(r==0) break;//剩下的元素都相同
    }
    return vec.back();
}

//更好的方法，用计数来确定
template<typename T> T HalfAppearInArray(T *a,size_t sz)
{
    if(a==NULL||sz<=0)
        throw std::runtime_error("container is empty or parameter error.");
    int flag = 1;
    T *p=&(a[0]);
    for(size_t i=1;i<sz;++i)
    {
        if(*p==a[i])
            ++flag;
        else{
            --flag;
            if(flag<0){
                flag=1;
                *p = a[i];
            }
        }
    }
    return *p;
}

void testcase1()
{
    int a[]={2,4,3,1,1,1,1};
    cout<<HalfAppearInArray(a,sizeof(a)/sizeof(a[9]))<<endl;
}

int main(int argc, char *argv[])
{
    int a[]={1,1,1,2,3,4,5,1,1};

    cout<<halfAppearInArray<int>(a,sizeof(a)/sizeof(a[0]))<<endl;
    cout<<HalfAppearInArray<int>(a,sizeof(a)/sizeof(a[0]))<<endl;

    testcase1();
    return 0;
}
