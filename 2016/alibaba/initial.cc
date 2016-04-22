#include <iostream>
using namespace std;

class A{
    //public:
        //A(int a):a_(a){}
    private:
        int a_;
};

class B:public A{
    public:
        B(int b_,A& c_):b(b_),c(c_){}
    private:
        int a_;//由于无法访问A的a_,所以不需要初始化区别
    public:
        const int b;//需要初始化列表
        A &c;//需要初始化列表
        static const char* d;

        B *e;

        int a(){return a_;}//访问的是B::a_
};

const char* B::d = "hello";
int main()
{
    A a;//(15);
    B b(7,a);
    char str[]="hello";
    cout<<B::d<<endl;
    cout<<b.a()<<endl;
    return 0;
}
