#include <iostream>
#include <algorithm>

using namespace std;

//是偶数
bool isEven(int n)
{
    return (n&0x1)==0;
}

void Reorder(int a[],int sz,bool (*func)(int))
{
    if(a==NULL||sz<=0)
        return;
    int i=0,j=sz-1;
    while(i<j){
        while((!func(a[i])) && i<j) ++i;//满足预设条件,跳过
        while(func(a[j]) && i<j) --j;
        swap(a[i],a[j]);//不满足条件,交换
    }
}

void testcase1()
{
    if(!(isEven(2)&& isEven(-2)))
        throw std::runtime_error("Even ERROR.");
    int a[]={};
    int b[]={1,3};
    int c[]={2,1,3};
    int d[]={2,4,1,3};

    Reorder(a,5,isEven);
    Reorder(b,2,isEven);
    cout<<"b:"<<b[0]<<'\t'<<b[1]<<endl;
    Reorder(c,3,isEven);
    cout<<"c:"<<c[0]<<'\t'<<c[1]<<'\t'<<c[2]<<endl;
    Reorder(d,4,isEven);
    cout<<"d:"<<d[0]<<'\t'<<d[1]<<'\t'<<d[2]<<'\t'<<d[3]<<endl;
}

int main(int argc, char *argv[])
{
    testcase1();
    return 0;
}
