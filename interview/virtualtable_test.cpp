#include <iostream>
#include <cmath>
using namespace std;

//相当于接口
class Base{
    public:
        virtual int Perimeter()=0;
        virtual int Area() = 0;
};

//不全实现虚基类也可以通过编译
class Shape:public Base{
    public:
        virtual int Perimeter();//仍然是虚函数
};

int Shape::Perimeter()
{
    cout<<"[Shape Perimeter]方法."<<endl;
    return 0;
}

class Rectangle:public Shape{
    public:
        Rectangle(int _w,int _h):w(_w),h(_h){}
        int Perimeter()
        {
            cout<<"[Rectangle Perimeter]方法."<<endl;
            return (w+h)<<1;
        }
        //多态依然能够找到该方法执行
        int Area()
        {
            cout<<"[Rectangle Area]方法."<<endl;
            return w*h;
        }

        //特有方法
        double dialog()
        {
            double d = w*w+h*h;
         /*   double k=1.0;
            double esp;
            while((esp>=-1e-9)||(-esp>=1e-9)){
                k = (k+d/k)/2;
                esp = k*k-d;
            }
            return k;
            */
            return sqrt(d);
        }
    private:
        int w,h;
};

class NullDerived:public Shape{

};

class Rect{
    int w,h;
};

class Null{
};

class NullReciver{
    public:
        void receive();
};

class NullMethod{
    public:
        virtual void call();
};
void NullMethod::call()
{
}

void testcase1()
{
    cout<<"虚基类:"<<sizeof(Base)<<endl;
    cout<<"实现虚基类部分接口的类:"<<sizeof(Shape)<<endl;
    /*从结果来看无继承，class size之和变量的类型以及数量有关
     *继承含有虚函数的类后，class size 的结果需要加上虚函数表指针大小
     * class_size = m_val_size+virtual_table_pointer_size
     */
    cout<<"继承父类，有成员变量的实子类:"<<sizeof(Rectangle)<<endl;
    cout<<"继承父类的空类:"<<sizeof(NullDerived)<<endl;
    cout<<"无继承，有成员变量的类:"<<sizeof(Rect)<<endl;

    cout<<endl;
    //隐含继承
    Base *pb = new Rectangle(6,8);
    //测试调用方法的继承路径
    cout<<pb->Perimeter()<<endl;
    //通过虚函数表找到方法执行
    cout<<pb->Area()<<endl;
    //由虚基类中的Area方法
    Shape *ps = new Rectangle(10,12);
    cout<<ps->Perimeter()<<endl;
    //向下转型调用特有方法
    //cout<<"对角线长度:"<<ps->dialog()<<endl;
    if(Rectangle *pr = dynamic_cast<Rectangle*>(ps)){
        cout<<"对角线长度:"<<pr->dialog()<<endl;
    }
    delete pb,ps;
}

void testcase2()
{
    //测试空类，只有成员函数的类，只有虚函数的类
    cout<<"空类:"<<sizeof(Null)<<endl;
    cout<<"类只有成员函数:"<<sizeof(NullReciver)<<endl;
    cout<<"类只有虚函数:"<<sizeof(NullMethod)<<endl;
}
int main(int argc, char *argv[])
{
    testcase1();
    testcase2();
    return 0;
}
