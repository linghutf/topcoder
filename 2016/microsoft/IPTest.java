import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

/**
 * Created by xdc on 2016/4/6.
 */
public class IPTest {
    public static void main(String[] args){
        ReadRules rr = new ReadRules();
        rr.readFile("data");
    }
}

class Rule{
    private String ruler;
    private String ipstr;

}

class ReadRules{
    public void readFile(String filename){
        try {
            FileInputStream fis=new FileInputStream(filename);

            Scanner s = new Scanner(fis);
            int m = s.nextInt();
            int n = s.nextInt();
            s.nextLine();//仍然是第一行

            List rules = new ArrayList<String>();
            List ips = new ArrayList<String>();
            int i;
            for(i=0;i<m;++i)
                rules.add(s.nextLine());
            for(i=0;i<n;++i)
                ips.add(s.nextLine());
            List rs = getRules(rules," ");

            print(m,n,rs,ips);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public List<String> getRules(List list,String delim){
        List result = new ArrayList<String>();
        Iterator it = list.iterator();
        while(it.hasNext()){
            String[] rs = ((String)it.next()).split(delim);
            for(String s:rs){
                result.add(s);
            }
        }
        return result;
    }

    public void print(int m,int n,List rules,List ips){
        System.out.printf("%4d%4d\n",m,n);
        Iterator it = rules.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
        it = ips.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
    }
}
