#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Test{
    public:
        Test(const char *str=NULL);
        Test(const Test &t);
        Test &operator=(const Test &t);
        ~Test();

        const char *Addr();
        const char *string();
    private:
        char *s;
};

Test::Test(const char *str)
{
    this->s=NULL;
    if(str!=NULL){
        this->s=new char[strlen(str)+1];
        strcpy(this->s,str);
    }
}

Test::Test(const Test &t)
{
    //清理之前的内容
    //这里容易出问题
    /*if(this->s!=NULL)
        delete []this->s;
*/
    this->s=new char[strlen(t.s)+1];
    strcpy(this->s,t.s);
}

Test& Test::operator=(const Test &t)
{
    //异常安全赋值
    Test tmp(t);
    cout<<"tmp:"<<tmp.string()<<endl;
    char *data;
    if(this!=&t){
        data=tmp.s;
        tmp.s=this->s;
        this->s=data;
        //swap(this->s,tmp.s);//tmp对象会被释放
    }
    //自身对象
    return *this;
}

Test::~Test()
{
    if(this->s!=NULL)
        delete []this->s;
}

const char *Test::Addr()
{
    return this->s;
}

const char *Test::string()
{
    return this->s;
}

void printInfo(Test &t)
{
    printf("addr:%p,str:%s\n",t.Addr(),t.string());
}

int main(int argc, char *argv[])
{
    Test t1("hello");
    Test t2(t1);
    cout<<"T1---";
    printInfo(t1);

    cout<<"T2---";
    printInfo(t2);

    Test t3=t1;
    cout<<"T3---";
    printInfo(t3);

    Test *p=&t1;
    cout<<"P ---";
    printInfo(*p);

    return 0;
}
