/**
 *
 * 父类对象调用子类方法
 * super virtaul method
 *
 */
#include <iostream>
#include <string>

using namespace std;

class Base{
    public:
    //virtual void g()=0;
    //virtual string f()=0;//不能实例化Base
    virtual string f(){return "Base";}
    virtual bool operator()(int x,int y)
    {
        return x<y;
    }
};
class A:public Base{
    public:
    virtual string f(){return "A";}
    virtual bool operator()(int x,int y)
    {
        return x==y;
    }
};
class B:public Base{
    public:
    virtual string f(){return "B";}

    virtual bool operator()(int x,int y)
    {
        return x>y;
    }
};

int main(int argc, char *argv[])
{
    Base *pb = new A;
    cout<<pb->f()<<endl;//A

    //*pb ();
    A();
    //b();

    delete pb;

    pb = new Base;
    cout<<pb->f()<<endl;//A
    delete pb;

    //A *pa = new Base;//error
    //cout<<pa->f()<<endl;
    return 0;
}
