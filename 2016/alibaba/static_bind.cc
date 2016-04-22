/**
 * 缺省参数静态绑定
 */
#include <iostream>

using namespace std;

class A{
    public:
        virtual void func(int val=1){
            cout<<"A->"<<val<<endl;
        }
        virtual void test(){
            func();
        }
};

class B:public A{
    void func(int val=0){
        cout<<"B->"<<val<<endl;
    }
};

int main()
{
    B *p = new B;
    p->test();//调用A::test,调用B::func,由于func多台函数对缺省参数无影响，val=1输出B->1
    delete p;
    return 0;
}
