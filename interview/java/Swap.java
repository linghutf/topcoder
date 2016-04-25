import java.util.Arrays;

public class Swap{
    public static void swap(Integer a,Integer b){//拷贝引用,不能交换
        int tmp = a.intValue();
        //a.setValue(b.intValue());//没有set方法，所以不能成功
    }

    public static void swap(int[] arr){//数组首地址引用复制，实际指向的对象相同,可以交换
        int t = arr[0];
        arr[0]=arr[1];
        arr[1]=t;
    }

    public static void main(String[] args){
        int a=10,b=12;
        int[] arr={a,b};
        Swap.swap(arr);
        a=arr[0];
        b=arr[1];
        System.out.println("a="+a+",b="+b);
    }
}
