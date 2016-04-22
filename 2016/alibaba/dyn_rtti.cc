#include <iostream>
using namespace std;

class A{
    public:
        A():m_iVal(0){test();}
        virtual void fun(){cout<<m_iVal<<' ';}
        void test(){fun();}
    public:
        int m_iVal;
};

class B:public A{
    public:
        B(){test();}
        virtual void fun()
        {
            ++m_iVal;
            cout<<m_iVal<<' ';
        }
        //void test(){cout<<"overload\n";}
};

int main()
{
    //B对象初始化，首先调用A的构造函数A()
    //A::test调用多态函数fun(),现在是初始化A对象，调用A::fun,输出0

    //再对B对象的初始化,调用test;
    //由于B没有重载test，因此调用A::test
    //现在是初始化B对象，test调用B::fun,输出1
    A *p = new B;//B()->A():test()->0,B::fun()->1

    //调用A::test.由于是B对象，调用B::fun,输出2
    p->test();//B::test->B::fun()->2
    return 0;
}
