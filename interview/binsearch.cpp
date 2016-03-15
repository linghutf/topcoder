#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> int binsearch(const T& key,const T* a,size_t sz, int (*compare)(const T& x,const T& y))
{

    if(a==NULL||sz<=0)
        return -1;
    int low=0,high= sz-1;
    int mid,flag;
    while(low<=high){
        mid = (low+high)/2;
        flag = compare(a[mid],key);
        if(flag<0) low=mid+1;//mid<key
        else if(flag==0) return mid;
        else high=mid-1;//mid>key
    }
    return -1;//not found.
}

int cmp(const int& a,const int& b)
{
    return a-b;
}

int main(int argc, char *argv[])
{
    int a[]={1,2,3,5,7,9,21};
    int len = sizeof(a)/sizeof(a[0]);
    std::for_each(a,a+len,[](auto &i){cout<<i<<'\t';});
    cout<<endl;

    int key = atoi(argv[1]);
    //auto cmp = [](const int &i,const int &j){return i-j;};
    cout<<"find pos:"<<binsearch<int>(key,a,len,cmp)<<endl;
    return 0;
}
