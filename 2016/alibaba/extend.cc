#include <iostream>
using namespace std;

class A{
    public:
        void func(){cout<<"A"<<endl;}
};

class B:public A{};

int main()
{
    B b;
    b.func();//继承的是A::func
    return 0;
}
