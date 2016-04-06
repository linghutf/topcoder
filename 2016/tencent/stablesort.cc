/**
 * 归并排序 稳定 nlgn
 * 堆排序        nlgn
 */
#include <iostream>
#include <algorithm>
#include <iomanip>

#include <cstdlib>
#include <ctime>

using namespace std;

struct Object{
    int id;
    int age;
    Object():id(0),age(0){}
    Object(int id_,int age_):id(id_),age(age_){}

    friend ostream& operator<<(ostream &os,Object &obj){
        os<<setw(5)<<'['<<obj.id<<','<<obj.age<<']';
        return os;
    }
};

struct Base{
    virtual bool operator()(const Object &a,const Object &b)
    {}
    //virtual bool cmp(const Object &a,const Object &b);
};

struct CmpId:public Base{
    virtual bool operator()(const Object &a,const Object &b)
    //bool cmp(const Object &a,const Object &b)
    {
        return a.id<b.id;
    }
};

struct CmpAge:public Base{
    virtual bool operator()(const Object &a,const Object &b)
    //bool cmp(const Object &a,const Object &b)
    {
        return a.age<b.age;
    }
};

void HeapSort(Object *objs,int num,int type)
{
    //void *raw;
    //CmpId *p;
    //CmpAge *q;
    //Base *pb;//(*pb)是Base对象，所以(*pb)()不能动态重载
    switch(type){
        case 1:
            std::make_heap(objs,objs+num,CmpId());
            for(int i=0;i<num;++i){
                std::pop_heap(objs,objs+num-i,CmpId());
            }
            //pb = new CmpId;
            break;
        case 2:
            std::make_heap(objs,objs+num,CmpAge());
            for(int i=0;i<num;++i){
                std::pop_heap(objs,objs+num-i,CmpAge());
            }
            /*
            raw = operator new(sizeof(CmpAge));
            q=static_cast<CmpAge*>(raw);
            */
            //pb = new CmpAge;
            break;
    }

}

void Print(Object *objs,int num)
{
    for(int i=0;i<num;++i){
        cout<<objs[i];
    }
    cout<<endl;
}

void testcase()
{
    srand(time(NULL));

    Object objs[10];
    int len = 10;
    for(int i=0;i<len;++i){
        objs[i].id=rand()%len;
        objs[i].age=rand()%100;
    }

    Print(objs,len);

    HeapSort(objs,len,1);
    Print(objs,len);

    HeapSort(objs,len,2);
    Print(objs,len);
}

int main(int argc, char *argv[])
{
    testcase();

    return 0;
}
