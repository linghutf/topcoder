#include <iostream>
#include "selectsort.hh"

class MyInt:public sort::ISort
{
    public:
        MyInt():_value(0){}
        MyInt(int v):_value(v){}

        virtual bool operator<(sort::ISort & rhs)
        {

            return _value<((MyInt&)rhs)._value;
        }

        void set_value(int n)
        {
            this->_value = n;
        }

        int value()
        {
            return this->_value;
        }

    private:
        int _value;
};

int main(int argc, char *argv[])
{
    const int len = 3;
    MyInt a[len];
    a[0].set_value(3);
    a[1].set_value(-1);
    a[2].set_value(2);
    sort::Sort::select_sort(a,len);

    return 0;
}
