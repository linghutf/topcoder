/**
 * 虚析构函数的作用
 */
#include <iostream>
#include <cstring>

using namespace std;

class Base{
    public:
        Base()
        {
            cout<<"Base construction..."<<endl;
        }
        virtual ~Base()//会调用子类析构函数
        {
            cout<<"Base deconstruction..."<<endl;
        }

};

class Derived:public Base{
    public:
        Derived(const char *str=NULL)
        {
            s = new char[strlen(str)+1];
            strcpy(s,str);
            cout<<"Derived construction..."<<endl;
        }

        ~Derived()
        {
            if(s!=NULL)
                delete []s;
            cout<<"Derived deconstruction..."<<endl;
        }

    private:
        char *s;
};

int main(int argc, char *argv[])
{
    Base *p = new Derived("I'm derived.");
    delete p;
    //查看内存泄露了没有
    return 0;
}
