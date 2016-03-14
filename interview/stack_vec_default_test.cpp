#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

using namespace std;

void sum(int &s,int a,int b)
{
    s=0;
    for(int i=a;i<b;++i)
        s+=i;
    //return s;
}

void vector_defaultVal_testcase()
{
    std::vector<int> v;
    //可分配的默认栈区大小
    const unsigned long sz = 1024*1024;
    int d[sz]={0};//int:8byte,1024*1024=1M==>8MB
    d[sz-1]=100;
    cout<<d[sz-1]<<endl;

    //vector不受大小影响
    v.resize(sz*2);
    v[sz*2-1]=100;
    cout<<"size:"<<v.size()<<"val:"<<v[sz*2-1]<<endl;
}

int main(int argc, char *argv[])
{
    std::vector<std::thread> t;// = new std::thread[10];
    int s[10];
    int len =10;
    for(int i=0;i<len;++i)
        t.push_back(std::thread(sum,std::ref(s[i]),i*10,(i+1)*10));
    for(int i=0;i<len;++i)
        t[i].join();
    cout<<std::accumulate(s,s+len,0)<<endl;

    vector_defaultVal_testcase();
    return 0;
}
