import java.util.LinkedList;
import java.util.Collections;

public class ListSortTest{
    public static void main(String... args){
        LinkedList<Integer> list = new LinkedList<Integer>();
        list.add(1);
        list.add(-2);
        list.add(13);

        Collections.sort(list,Collections.reverseOrder());
        System.out.println(list.toString());

    }
}
