#include <iostream>

class Base{
    public:
        explicit Base()
        {
            std::cout<<"base"<<std::endl;
        }
        virtual void foo()
        {
            std::cout<<"base_foo\n";
        }
        void bar()
        {
            std::cout<<"base_bar\n";
        }
};

class Derived:public Base{
    public:
        Derived()
        {
            std::cout<<"derived"<<std::endl;
        }

        virtual void foo()
        {
            std::cout<<"derived_foo\n";
        }
        void bar()
        {
            std::cout<<"derived_bar\n";
        }
};


int main(int argc, char *argv[])
{
    Derived df;
    Base &pb = df;//new Derived;
    std::cout<<"多态:\n";
    pb.foo();
    pb.bar();
    Derived &pd = dynamic_cast<Derived&>(pb);//向下转型
    std::cout<<"dyn转换:\n";//ok
    pd.foo();
    pd.bar();
    std::cout<<"sta转换:\n";
    Base &pr = static_cast<Base&>(df/*&pd*/);//向上转型
    pr.foo();//没有成功
    pr.bar();
    return 0;
}
