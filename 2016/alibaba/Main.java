public class Main{
    //不是main方法
    public static void main(){
        System.out.println("this main no args.");
    }
    //不是main方法
    public static void main(String arg){
        System.out.println("this main one arg.");
    }

    public static void main(String[] args){
        ((Main)null).main();
    }
    public void func(){
    }
}
