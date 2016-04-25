import java.util.Arrays;
import java.lang.reflect.Array;

public class ArrayCopy{
    /**
     *
     */
    public static Object copyOf(Object a,int newLength){
        Class c = a.getClass();
        if(!c.isArray()) return null;
        Class componentType = c.getComponentType();
        int length = Array.getLength(a);
        //new Array
        Object newArray = Array.newInstance(componentType,newLength);
        System.arraycopy(a,0,newArray,0,Math.min(length,newLength));
        return newArray;
    }

    public static void main(String... args){
        int[] a={1,3,2,4};
        int[] na = (int[])copyOf(a,3);
        System.out.println(Arrays.toString(na));

        String[] ss = {"Hello","Java","C++","Python"};
        String[] nss = (String[])copyOf(ss,ss.length);
        System.out.println(Arrays.equals(ss,nss));
    }

}
