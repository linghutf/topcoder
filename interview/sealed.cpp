/**
 * 不能被继承的类
 */
#include <iostream>

template<typename T> class MakeSealed{
    //public:
        friend T;
    private:
        MakeSealed(){}
        virtual ~MakeSealed(){}

};

class SealedObject:virtual public MakeSealed<SealedObject>{
    public:
        SealedObject(){}
        virtual ~SealedObject(){}
};

class Derived:public SealedObject{
    public:
        Derived(){}
        ~Derived(){}
};

void testcase()
{
    SealedObject obj;
    SealedObject *pObj = new SealedObject;
    delete pObj;

    //测试继承
    Derived d;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
