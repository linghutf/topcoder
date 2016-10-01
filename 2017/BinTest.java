public class BinTest{

    public static void main(String[] args){
        testcase();

    }

    public static void testcase(){
        String s = "1111111100000000";
        int n = Integer.parseInt(s,2);
        System.out.println(n);
        System.out.println(Integer.toBinaryString(n));

    }
}
