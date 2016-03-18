#include <iostream>
#include "insertsort.hh"

using namespace std;

int main(int argc, char *argv[])
{
    int a[]={};
    auto cmp = [](int a,int b){return b-a;};//降序
    InsertSort(a,0,1,cmp);

    int b[]={3,-1,2,7,4};
    int len = sizeof(b)/sizeof(b[0]);
    InsertSort(b,0,len);//默认升序
    std::for_each(b,b+len,[](int n){cout<<n<<'\t';});
    cout<<endl;
    return 0;
}
