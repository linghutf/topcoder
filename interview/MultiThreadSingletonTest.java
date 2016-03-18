public class MultiThreadSingletonTest{
    public static void main(String[] args) {
        Thread t1 = new Thread(new Runnable(){
            public void run(){
                MultiThreadSingleton t = MultiThreadSingleton.getInstance();
                MultiThreadSingletonLockFree tf = MultiThreadSingletonLockFree.getInstance();
                System.out.println(t);
                System.out.println("lock-free:"+tf);
            }
        });
        Thread t2 = new Thread(new Runnable(){
            public void run(){
                MultiThreadSingleton t = MultiThreadSingleton.getInstance();
                MultiThreadSingletonLockFree tf = MultiThreadSingletonLockFree.getInstance();
                System.out.println(t);
                System.out.println("lock-free:"+tf);
            }
        });
        t1.start();
        t2.start();
    }

}

class MultiThreadSingleton{
    private MultiThreadSingleton instance=null;
    private MultiThreadSingleton(){}

    public synchronized MultiThreadSingleton getInstance(){
        if(instance==null){//每次查询都锁住，效率差
            instance = new MultiThreadSingleton();
        }
        return instance;
    }
}

class MultiThreadSingletonLockFree{
    private MultiThreadSingletonLockFree instance=null;
    private MultiThreadSingletonLockFree(){}

    public MultiThreadSingletonLockFree getInstance(){
        if(instance==null){//只在第一次创建的时候锁住
            synchronized(MultiThreadSingletonLockFree.class){
                if(instance==null)
                    instance = new MultiThreadSingletonLockFree();
            }
        }
        return instance;
    }
}

class MultiThreadSingletonStatic{
    private static MultiThreadSingletonStatic instance=new MultiThreadSingletonStatic();
    private static MultiThreadSingletonStatic(){}

    public static MultiThreadSingletonStatic getInstance(){
        return instance;
    }
}