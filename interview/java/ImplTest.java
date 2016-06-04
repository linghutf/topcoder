/**
 * 测试多implements
 */
interface Human{
    public void say();
}

interface Animal{
    public void asleep();
}

public class ImplTest implements Animal,Human{
    private String name;
    private int sleeptime;

    public ImplTest(String name,int sleeptime){
        this.name = name;
        this.sleeptime = sleeptime;
    }

    public static void main(String[] args){
        ImplTest t = new ImplTest("张三",7);
        Human h = t;
        h.say();
        Animal a = t;
        a.asleep();
    }

    @Override
    public void say(){
        System.out.println("I'm "+this.name);
    }

    @Override
    public void asleep(){
        System.out.println("I'm sleeping "+this.sleeptime+" hours.");
    }
}
