public class Example{
    String str=new String("hello");//final,不能修改
    char[] ch = {'a','b'};
    public static void main(String[] args){
        Example ex = new Example();
        ex.exchange(ex.str,ex.ch);
        System.out.println(ex.str+" and "+new String(ex.ch));//test ok and ab

        String s="";
        int i = 12;
        Integer ii = new Integer(12);
        ex.change(s);
        ex.change(i);
        ex.change(ii);
        int m=2,n=5;
        ex.swap(m,n);
        System.out.println("result:"+s+",i:"+i+",ii:"+ii);//没有改变
        System.out.println("m:"+m+",n:"+n);//没有改变
        MyInteger M = new MyInteger(2);
        MyInteger N = new MyInteger(5);
        M.swap(N);
        System.out.println("M:"+M+",N:"+N);
    }
    public void exchange(String str,char ch[]){
        str = "test ok";//生成了新的String
        ch[0] = 'c';
    }//退出作用域,恢复原来的指向

    public void change(String s){
        s = "test new pointer.";
    }

    public void change(Integer a){
        a = 10;
    }

    public void swap(Integer a,Integer b){
/*不能成功
        Integer t = a;
        a=b;
        b=t;
*/
        /*
        Integer t = new Integer(a.intValue());
        a.setValue(b.intValue());
        b.setValue(t.intValue());
        */
    }
}

class MyInteger{
    private int a;
    public MyInteger(int a){
        this.a=a;
    }
    public void setValue(int a){
        this.a=a;
    }
    public int intValue(){
        return this.a;
    }

    public void swap(MyInteger b){
        MyInteger t = new MyInteger(this.a);
        this.a = b.intValue();
        b.setValue(t.intValue());
    }

    public static void swap(Integer a,Integer b){
        MyInteger i = new MyInteger(a.intValue());
        MyInteger j = new MyInteger(b.intValue());
        i.swap(j);
    }

    public String toString(){
        return ""+this.a;
    }

}
