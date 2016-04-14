#include <iostream>
using namespace std;

class Base{
    public:
        virtual void f(){cout<<"Base::f"<<endl;}
        virtual void g(){cout<<"Base::g"<<endl;}
        virtual void h(){cout<<"Base::h"<<endl;}
};

typedef void (*Fun)();

int main(int argc,char *argv[])
{
    Base b;
    Fun pFun = NULL;

    cout<<"虚函数表地址:"<<(int*)(&b)<<endl;
    cout<<"vtable:第一个函数地址:"<<(int*)*(int*)(&b)<<endl;

    pFun = (Fun)*((int*)*(int*)(&b));//第一个地址处的函数
    pFun();

    int *p = (int*)*(int*)(&b);
    pFun = (Fun)*(p+6);
    cout<<"结束位置的值:"<<*pFun<<endl;//1,表示还有下一个虚函数表

    /*
    int *p = (int*)*(int*)(&b);
    pFun = (Fun)*(p+2);
    pFun();//base::g
    pFun = (Fun)*(p+4);
    pFun();//base::f
    */
    //64位系统,函数指针大小8byte,p+2

    pFun = (Fun)*((int*)*(int*)(&b)+2);//第二个地址处的函数
    pFun();

    pFun = (Fun)*((int*)*(int*)(&b)+4);//第三个地址处的函数
    pFun();

    //检查两个对象的虚函数表是否相同
    Base bo;
    cout<<"虚函数表地址:"<<(int*)(&bo)<<endl;//虚函数表地址，不相同
    cout<<"第一个函数地址:"<<(int*)*(int*)(&b)<<endl;//虚函数表所指向的函数地址相同
    return 0;
}
