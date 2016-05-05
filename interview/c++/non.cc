#include <iostream>
using namespace std;

class A{
    private:
        int say(int);
        int value_;
    public:
        int say(int,int);//重载

        A(int n):value_(n){}
        //ERROR
        /*
        A(A a)
        {
            value_ = a.value_;
        }
        */
        A(const A& a):value_(a.value_){}

        //编译器实现=
        A& operator=(const A& a){
            this->value_ = a.value_;
            return *this;
        }

        int value(){return value_;}
};

int main()
{
    A a = 10;
    A b = a;

    cout<<b.value()<<endl;
    return 0;
}
