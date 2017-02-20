#include <iostream>

class Base{
    public:
        virtual void foo()=0;
};

void Base::foo()
{
    std::cout<<"default foo\n";
}


class Derived:public Base{
    public:
        void bar(){}
        // 必须实现
        virtual void foo(){std::cout<<"derived foo\n";}
};

int main(int argc, char *argv[])
{
    Derived d;
    d.foo();

    // 错误
    //Base b;
    //b.foo();
    Base *pb = &d;
    pb->foo();
    return 0;
}
