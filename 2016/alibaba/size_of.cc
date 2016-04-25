#include <iostream>
#include <algorithm>
using namespace std;

#pragma pack(2)

struct Test{//22
    int n;//4
    char str[13];//13->14
    int m;//4

    typedef void (*Func)();
    void fn(){};
};

struct Fun{//1
    int add(int,int);
    int sub(int,int);
    static void print();
    typedef int (*PFunc)(int,int);
};

int main()
{
    cout<<"Test size:"<<sizeof(Test)<<endl;
    cout<<"Fun  size:"<<sizeof(Fun)<<endl;

    return 0;
}
