/**
 * 测试JDK 7 文件读写
 */
import java.nio.file.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;

public class FileRead{
    public static void main(String[] args) {
        //Scanner s = new Scanner()
        //BufferedOutputStream bout = new BufferedOutputStream();
        //List<String> lst = Files.readAllLines(args[0]);
        Path path = Paths.get(args[0]);
        BufferedReader br = null;
        if(Files.isReadable(path)){
            try{
                br = Files.newBufferedReader(path);
                int BUFSIZ = 8192;
                char[] buf = new char[BUFSIZ];
                int off = 0;
                int sz = br.read(buf,off,BUFSIZ);
                if(sz!=-1){
                    String s = new String(buf,0,sz);
                    System.out.println(s);
                }
            }catch(IOException e){
                e.printStackTrace();
            }finally{
                try{
                    if(br!=null){
                        br.close();
                    }
                }catch(IOException e){
                    e.printStackTrace();
                }
            }

        }
    }
    /*
       public static void visit(String path){
        SimpleFileVisitor v = new SimpleFileVisitor();
    }
*/
}
