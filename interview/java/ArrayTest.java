import java.util.Arrays;
public class ArrayTest{
    public static void main(String[] args){
        int rows = 10,cols = 8;
        int n = rows*cols;
        int[][] a = new int[rows][];
        for(int i =0;i<a.length;++i){
            a[i]=new int[cols];
            for(int j=0;j<a[i].length;++j){
                a[i][j]= --n;
            }
        }

        System.out.println(Arrays.deepToString(a));

        for(int[] row:a){
            Arrays.sort(row);
        }
        System.out.println(Arrays.deepToString(a));

        System.out.println("75:"+Arrays.binarySearch(a[0],75));
    }
}
