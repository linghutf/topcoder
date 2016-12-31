import java.util.*;

public class HashMapTest{
    public static void main(String[] args) {
        HashMap<Integer,Integer> map = new HashMap<>();
        // 测试插入null value  OK
        map.put(1,null);

        // 查找两次才能得到值是否存在
        Object v = new Integer(-1);
        if(map.containsKey(1))
        {
            v = map.get(1);
        }

        System.out.println(v);

        map.put(null,12);//ok
        System.out.println("hashmap len:"+map.size());
        System.out.println("null:"+map.get(null));
        System.out.println("notExist:"+map.get(13));
        // 依然不存在
        if(map.containsKey(13))
        {
            System.out.println(map.get(13));
        }
    }
}
