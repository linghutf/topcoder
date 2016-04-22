#include <iostream>
using namespace std;

void func(const int &val1,const int &val2)
{
    cout<<val1<<","<<val2<<endl;
}

int main()
{
    int a=0;
    func(++a,a++);
    return 0;
}
