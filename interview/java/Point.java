import java.util.Objects;

public class Point{
    private int x,y;
    public Point(int x,int y){
        this.x = x;
        this.y = y;
    }

    public int getX(){return this.x;}
    public int getY(){return this.y;}

    public void setX(int x){
        this.x = x;
    }
    public void setY(int y){
        this.y = y;
    }

    public static void main(String[] args){
        Point x = new Point(12,10);
        Point y = new Point(10,12);
        if(x.equals(y)){
            System.out.println("equals failed.");
        }
        System.out.println(x+","+x.hashCode());
        System.out.println(y+","+y.hashCode());

    }

    @Override
    public boolean equals(Object obj){
        if(this==obj) return true;
        if(obj==null) return false;
        if(this.getClass()!=obj.getClass()) return false;
        Point other = (Point)obj;
        return other.getX()==this.getX() && other.getY()==this.getY();
    }

    @Override
    public int hashCode(){
        return Objects.hash(x,y);
    }

    @Override
    public String toString(){
        return this.getClass().getName()+"(x="+this.getX()+",y="+this.getY()+")";
    }
}
