public class ChangeValue{
    public static void main(String[] args){
        Integer i = -1;
        test(i);
        System.out.println(i);
    }

    public static void test(Integer i){
        i = new Integer(10);
    }
}
