public class EqualsTest{
    //Equals标准
    @Override
    public boolean equals(Object obj){
        if(this==obj) return true;
        if(obj==null) return false;
        //3.如果每个子类有明显改变
        //if(this.getClass() != obj.getClass()) return false;
        //或者 如果子类有统一的比较方式,抽象类
        //if(!(obj instanceof ClassName)) return false;
        //4.比较实例域
        //ClassName other = (ClassName)obj;
        //return filed1 = other.field1 && Objects.equals(field2,other.field1);
    }
}
