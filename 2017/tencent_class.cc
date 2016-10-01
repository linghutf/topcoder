#include <stdio.h>

struct A
{
    A(){bar();}
    void foo(){printf("foo");}
    virtual void bar(){printf("bar");};
};

struct B:public A
{
    void foo(){printf("b_foo");}
    void bar(){printf("b_bar");}
};

int main(int argc, char *argv[])
{
    A * p = new B;
    p->foo();
    p->bar();
    delete p;
    return 0;
}
