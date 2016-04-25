import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Objects;

class HashMap<K extends Comparable<K>,V>{

    private ArrayList<LinkedList<Pair<K,V>>> list;

}

class Pair<K extends Comparable<K>,V>{
    private K first;
    private V second;
    public Pair(){
        this.first = null;
        this.second = null;
    }

    public Pair(K first,V second){
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(K other){
        return this.first.compareTo(other);
    }

    public K getFirst(){
        return this.first;
    }

    public V getSecond(){
        return this.second;
    }

    @Override
    public int hashCode(){
        return Objects.hash(this.getFirst(),this.getSecond());//this.getFirst().hashCode();
    }

    @Override
    @SafeVarargs
    public boolean equals(Object obj){
        if(this==obj) return true;
        if(obj == null) return false;
        if(!(obj instanceof Pair<K,V>))
                return false;
        return Objects.equals(this,(Pair<K,V>)obj);
    }

}
