public class Boxing{
    public static void main(String[] args){
        int i = 257;
        Integer j = new Integer(257);
        System.out.println(i==j);//自动拆箱
        System.out.println(j.equals(i));
    }
}
