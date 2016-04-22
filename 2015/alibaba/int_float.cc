#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int x=4;
    cout<<typeid((x>4)?99.9:9).name()<<endl;//转型成double
    return 0;
}
