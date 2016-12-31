/**
 * 测试自定义智能指针
 *
 */

#include <iostream>
#include <thread>

#include "smart_ptr.hh"

class Object{
    public:
        Object(int i):_p(new int(i)){
            std::cout<<"C"<<std::endl;
        }
        ~Object()
        {
            delete _p;
            std::cout<<"D"<<std::endl;
        }

        int get_num(){return *_p;}

    private:
        int * _p;
};

void test(smart_ptr<Object> ptr)
{
    //if(ptr!=NULL){
        std::cout<<ptr->get_num()<<std::endl;
    //}
}

int main(int argc, char *argv[])
{
    smart_ptr<Object> sp;
    for(int i=0;i<100;++i){
        sp = new Object(i);
    }

    std::thread t1(test,sp);
    std::thread t2(test,sp);
    t1.join();
    t2.join();
    return 0;
}
