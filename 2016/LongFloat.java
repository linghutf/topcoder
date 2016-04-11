public class LongFloat{
    public static void main(String[] args){
        //LongFLoat lf = new LongFloat();
        func();//ok
        //func2();//error
        System.out.println(trycatch(10));
    }

    public static float func(){
        long i = 3;
        return i;
    }
/*
    public static float func2(){
        double i = 4;
        return i;
    }
*/
    public static int trycatch(int b){
        try{
            b+=10;
            return b;
        }catch(RuntimeException e){
        }catch(Exception e){
        }finally{
            b+=10;
            return b;
        }
    }
}
