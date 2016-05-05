import java.io.*;

public class Write{
    public static void main(String[] args){
        try{
            PrintWriter out = new PrintWriter(new FileWriter("example.lst"),true);
            out.println("重要程度|效益");
            out.printf("%6.2f%6.2f\n",0.8,1.2);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
