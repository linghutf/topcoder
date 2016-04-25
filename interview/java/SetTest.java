import java.util.Set;
import java.util.Iterator;
import java.util.Scanner;
import java.util.HashSet;
public class SetTest{
    public static void main(String[] args){
        Set<String> words = new HashSet<>();
        long totalTime = 0;
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            String word = in.next();
            long callTime = System.currentTimeMillis();
            words.add(word);
            callTime = System.currentTimeMillis()-callTime;
            totalTime += callTime;
        }

        Iterator<String> iter = words.iterator();
        for(int i=0;i<=20 && iter.hasNext();++i){
            System.out.println(iter.next());
        }
        System.out.println("\n"+words.size()+" distinct words. "+totalTime+" ms.");
    }
}
