import java.util.ArrayList;
import java.util.HashSet;
import java.util.Collections;
import java.util.Scanner;

public class Last{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int k = in.nextInt();

        int y = cond(x,k);

        String sx = Integer.toBinaryString(~x);
        String sy = Integer.toBinaryString(y);
        String sk = Integer.toBinaryString(k);

        System.out.println("~x:"+sx);
        System.out.println(" k:"+sk);
        System.out.println(" y:"+sy);

    }

    public static int cond(int x,int k){
        if(k<=0) return -1;
        ArrayList<Integer> list = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>();

        for(int i=1;i<=(3*x);++i){
            if((x+i)==(x|i)){
                set.add(i);
            }
        }

        for(Integer n:set){
            list.add(n);
        }

        Collections.sort(list);
        if(k>list.size())
            return 0;

        return list.get(k-1);
    }
}
