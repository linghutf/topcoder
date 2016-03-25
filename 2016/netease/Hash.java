import java.util.*;

public class Hash{
    private String name;
    private int age;

    public Hash(String c,int a){
        this.name = c;
        this.age =a;
    }

    public void setName(String name){
        this.name = name;
    }
    public void setAge(int age){
        this.age = age;
    }
    //自定义实现hash和equal方法
    public int hashCode(){
        return this.name.hashCode()^new Integer(this.age).hashCode();
    }

    public boolean equals(Object obj){
        if(obj==null) return false;
        if(obj==this) return true;
        if(! (obj instanceof Hash)){
            return false;
        }
        Hash c = (Hash)obj;
        return this.name.equals(c.name) && this.age==c.age;
    }

    public String toString(){
        return this.name+','+this.age;
    }

    public static void main(String[] args) {
        Hash c = new Hash("123",18);
        Hash d = new Hash("123",18);

        System.out.println(c.equals(d));//相同
        //System.out.println(c.equals(new Object("123")));//相同
        System.out.println(c.hashCode()==d.hashCode());//相同

        HashSet<Hash> set = new HashSet<Hash>();
        set.add(c);

        System.out.println("插入结果:"+set.add(d));//插入失败
        //更改c以验证set中是否是同一个对象
        //hashset中保存的是c的引用
        //发生了改变
        c.setName("xxd");
        for(Hash h:set)
            System.out.println(h);

        System.out.println("插入结果:"+set.add(d));//插入失败

    }
}
