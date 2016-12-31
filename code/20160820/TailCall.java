/**
 * 测试Java尾递归
 * Java 具有尾递归
 */

public class TailCall{
    public static long fib(long x, long y, long n){
        return n<=2? y : fib(y,x+y,n-1);
    }

    public static long fibnacci(long n){
        return fib(1,1,n);
    }

    public static void main(String[] args){
        try{
            long n = Long.parseLong(args[0]);
            System.out.printf("%d:%d\n",n,fibnacci(n));
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
