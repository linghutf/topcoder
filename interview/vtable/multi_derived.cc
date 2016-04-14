#include <iostream>

using namespace std;
//虚函数表 缺点:
//1. 无法通过父类指针调用子类未覆盖的虚函数
//2. 可以通过地址访问父类私有虚函数

class Base{
    public:
        virtual void f(){cout<<"Base::f"<<endl;}
        virtual void g(){cout<<"Base::g"<<endl;}
        virtual void h(){cout<<"Base::h"<<endl;}
    private:
        virtual void bar(){cout<<"Base::bar"<<endl;}
        int b;
};

class Base2{
    public:
        virtual void f(){cout<<"Base2::f"<<endl;}
        virtual void g(){cout<<"Base2::g"<<endl;}
        virtual void h(){cout<<"Base2::h"<<endl;}
};

class Base3{
    public:
        virtual void f(){cout<<"Base3::f"<<endl;}
        virtual void g(){cout<<"Base3::g"<<endl;}
        virtual void h(){cout<<"Base3::h"<<endl;}
};

class Derived:public Base,public Base2,public Base3{
    public:
        void f(){cout<<"Dervied::f"<<endl;}
        virtual void foo(){cout<<"Derived::foo"<<endl;}
};

typedef void (*Func)();

void test_visit_private()
{
    Derived d;
    Func pfunc;

    int** pvtab = (int**)&d;//二维数组

    cout<<"访问父类私有虚函数:"<<endl;
    //访问私有虚函数
    pfunc = (Func)pvtab[0][6];//bar
    pfunc();

    //访问私有变量,错误
    //cout<<"私有变量:"<<d.b<<endl;

}

void testcase()
{
    Derived d;
    Func pfunc;

    int** pvtab = (int**)&d;

    cout<<"虚函数表测试:"<<endl;
    pfunc = (Func)pvtab[0][0];//Dervied::f
    pfunc();
    pfunc = (Func)pvtab[0][2];//Base::g
    pfunc();
    pfunc = (Func)pvtab[0][4];//Base::h
    pfunc();

    pfunc = (Func)pvtab[2][0];//Derived::f
    pfunc();
    pfunc = (Func)pvtab[2][2];//Base2::g
    pfunc();
    pfunc = (Func)pvtab[2][4];//Base2::h
    pfunc();


    pfunc = (Func)pvtab[3][0];//Derived::f
    pfunc();
    pfunc = (Func)pvtab[3][2];//Base3::g
    pfunc();
    pfunc = (Func)pvtab[3][4];//Base3::h
    pfunc();


    pfunc = (Func)pvtab[3][6];//0
    cout<<"结束位置:"<<*pfunc<<endl;

    pfunc = (Func)pvtab[4][0];//pvtab[4]==pvtab[2] ?
    pfunc();
    cout<<"子类:"<<(int)(pvtab[1])<<endl;
/*
    pfunc = (Func)pvtab[4][2];//Base2::g
    pfunc();
*/
}

void test_derived()
{
    Derived d;
    int *p = (int*)(&d);
    cout<<"子类未覆盖的虚函数地址:"<<*p<<","<<*p+2<<endl;
    Func pfunc = (Func)*p;
    //pfunc();
    pfunc = (Func)(*p+2);
    //pfunc();

}
int main()
{
    test_visit_private();

    testcase();

    test_derived();

    return 0;
}
