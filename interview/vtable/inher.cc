#include <iostream>
using namespace std;

class A{
    public:
        void rotate(){cout<<"A rotate.\n";}
};

class B:public A{
    public:
        void rotate(){cout<<"B rotate.\n";}
};

int main()
{
    B b;
    A &a = b;
    a.rotate();//A rotate,引起切割
    return 0;
}
