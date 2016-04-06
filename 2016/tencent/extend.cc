/**
 * 继承与static_cast转型
 */
#include <iostream>
using namespace std;

class X{
    public:
        virtual char f(){return 'X';}
};

class B:public X{
    public:
        virtual char f(){return 'B';}
};

class A:public X{
    public:
        virtual char f(){return 'A';}
};

class D:public A{
    public:
        virtual char f(){return 'D';}
};

class E:public A{
    public:
        virtual char f(){return 'E';}
};

int main(int argc, char *argv[])
{
    X *p[5];//指针数组
    int len=5;
    //void *raw =operator new[](len*sizeof(X)); //对象数组
    //X *p = static_cast<X*>(raw);

    p[0]=new X;
    p[1]=new A;
    p[2]=new B;
    p[3]=new D;
    p[4]=new E;
    int i;
    B *pb,*pc;
    for(i=0;i<len;++i){
        pb=static_cast<B*>(p[i]);
        cout<<pb->f()<<endl;//XABDE
        //cout<<((B*)p[i])->f()<<endl;//XABDE,效果相同

        //pc=reinterpret_cast<B*>(p[i]);//XABDE,效果相同
        //pc=dynamic_cast<B*>(p[i]);//错误
        //cout<<pc->f()<<endl;
        delete p[i];
    }

    //pb = new D;//错误，不是父类与子类的关系
    //cout<<pb->f()<<endl;


    return 0;
}
