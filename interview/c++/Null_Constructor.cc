#include <iostream>
using namespace std;

class A{
    private:
        int value_;
    public:
        A()=default;
        A(int n):value_(n){}
        ~A(){cout<<"deconstruct...\n";}
};

int main()
{
/*
    A *p = new A[10];//调用默认构造函数,由于编译器没有隐含实现，所以无法通过编译

    //p[0] = new A(12);//ERROR
    delete[] p;//调用10次析构函数

*/
    A **pa = new A*[10];
    pa[0] = new A(12);//OK
    delete pa[0];
    return 0;
}
