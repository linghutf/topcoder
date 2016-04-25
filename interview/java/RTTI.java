//import static java.lang.System.out.System.out.println;
public class RTTI{
    public static void main(String[] args){
        Base b = new Derived();
        b.test();//Base::say,静态绑定
        b.sleep();//Derived::sleep,动态绑定

        Derived d = (Derived)b;//行为与上一样
        d.test();
        d.sleep();

        d = new Derived();//与上一样
        d.test();//Base->say();
        d.sleep();
    }
}

class Base{
    private void say(){System.out.println("Base::say");}

    public void sleep(){System.out.println("Base::sleep");}

    public void test(){this.say();}//默认继承时,实际已指定了Base->say();
}

class Derived extends Base{
    private void say(){System.out.println("Derived::say");}

    public void sleep(){System.out.println("Derived::sleep");}

    //public void test(){say();}//全部是Derived->say();
}
