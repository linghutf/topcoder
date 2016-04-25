#include <iostream>
#include <typeinfo>

using namespace std;

class Object{
    public:

        Object(int id):id_(id){}
        friend ostream& operator<<(ostream& os,Object& obj)
        {
            os<<obj.id_;
            return os;
        }
    private:
        int id_;
};

template<typename T>void print(T& t)
{
    cout<<typeid(t).name()<<":"<<t<<endl;
}

int main(){
    int *x=new int;
    print(*x);
    double *f=new double();
    print(*f);
    //complex c();
    //print(c);

    Object obj = 1;//隐式转换// Object *pobj = new Object;//error
    print(obj);

    delete x;
    delete f;
    return 0;
}
