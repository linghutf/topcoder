/*
 *
 * 对于多态状态(父类指针指向子类),查找路径:
 *  this.call(O) -> super.call(O) -> this.call(super(O)) -> super.call(super(O))
 *
 * 对于非多态,查找路径:
 *  this.call(O) -> this.call(super(O)) ,一直向上转型,和Java不同，Java转型也是遵循上面一条线
 *
 */
#include <iostream>
#include <string>

using namespace std;

class B;
class C;
class D;

class A{
    public:
        virtual string show(A *obj){
            return "A and A";
        }
        //只在父类中
        virtual string show(D *obj){
            return "A and D";
        }
/*
 * 测试b.show(c) 查找路径
        virtual string show(C *obj){
            return "A and C";
        }
*/

};

class B:public A{
    public:
        //多态方法
        virtual string show(A *obj){
            return "B and A";
        }
        //只在子类中
        virtual string show(B *obj){
            return "B and B";
        }
};

class D:public B{
};

class C:public B{
};

int main()
{
    A *a1,*a2;
    B *b;
    a1 = new A;
    a2 = new B;
    b = new B;
    C *c = new C;;
    D *d = new D;

    cout<<a1->show(b)<<endl;//存在, a.show(b) : A and B
    cout<<a1->show(c)<<endl;//a.show(c) -> a.show(b) : A and B
    cout<<a1->show(d)<<endl;//存在, a.show(d) : A and D

    //多态
    cout<<a2->show(b)<<endl;//重载,  b.show(b) : B and A
    //不会查找到b.show(b),因为A中无定义
    cout<<a2->show(c)<<endl;//非重载,b.show(c) -> a.show(c) -> b.show(super(c)) -> b.show(super(b)) : B and A
    cout<<a2->show(d)<<endl;//非重载,b.show(d) -> a,show(d) : A and D

    //非多态
    cout<<b->show(b)<<endl;// 匹配,  b.show(b) : B and B
    cout<<b->show(c)<<endl;// b.show(c) -> b.show(super(c)) : B and B
    cout<<b->show(d)<<endl;// b.show(d) -> b.show(super(d)) : B and B

    delete a1,a2,b,c,d;

    return 0;
}
