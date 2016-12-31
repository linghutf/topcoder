#include <iostream>

void foo(int * p)
{
}

struct Baz
{
    const void bar(int * p) const
    {
    }

    void kik(const int * p)
    {
    }
};

struct Cell
{

};

void test_notify(const Cell * p)
{
    p = new Cell;
    delete p;
}

int main(int argc, char *argv[])
{
    const int N = 10;
    //foo(&N); // 错误 const int * to int *
    Baz b;
    //b.bar(&N); // error

    b.kik(&N); // ok

    Cell cell;
    test_notify(&cell);

    return 0;
}
