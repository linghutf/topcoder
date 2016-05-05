import java.util.ArrayList;
import java.util.PriorityQueue;;
import java.util.Random;
import java.util.Comparator;
import java.util.Collections;
import java.util.HashSet;

public class MinTopHeap{
    public static void main(String[] args){
        Random r = new Random();
        int k = 10;
        int nums = 1000;
        ArrayList<Integer> list = new ArrayList<>();

        Integer tmp;
        for(int i=0;i<nums;++i){
            tmp=r.nextInt(1000);
            list.add(tmp);
            //System.out.println(tmp.intValue());
        }
        int[] res = minTopK(list,k);
        if(res!=null){
            for(int n:res){
                System.out.println(n);
            }
        }

        //数据量小的时候，检查算法正确性
        if(checkErr(list,res))
            System.out.println("算法错误!");
    }
    //求最小的k个值
    public static int[] minTopK(ArrayList<Integer> list,int k){
        if(k<=0) return null;
        int num = k<list.size()?k:list.size();
        int[] res = new int[num];
        //大根堆
        PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>(){
            @Override
            public int compare(Integer a,Integer b){
                return b.compareTo(a);
            }
        });
        int i;
        for(i=0;i<k;++i){
            heap.add(list.get(i));
        }

        Integer top;
        for(;i<list.size();++i){
            top = heap.peek();
            if(top.compareTo(list.get(i))>0){
                heap.poll();
                heap.add(list.get(i));
            }
        }
        i=0;
        while(!heap.isEmpty()){
            res[i++]=heap.poll();
        }
        return res;
    }

    public static boolean checkErr(ArrayList<Integer> list,int[] res){
        Collections.sort(list);
        HashSet<Integer> set = new HashSet<>();

        for(int i=0;i<res.length;++i){
            set.add(list.get(i));
        }
        for(int n:res){
            set.remove(n);
        }

        return !set.isEmpty();
    }
}
