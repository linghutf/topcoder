

public class SingleThreadSingletonTest{
	
	public static void main(String[] args){
		SingleThreadSingleton s1 = SingleThreadSingleton.getInstance();
		SingleThreadSingleton s2 = SingleThreadSingleton.getInstance();
		if(s1==s2)
			System.out.println("[Normal Test]SingleThreadSingleton is OK.");

		MultiTest();
	}

	public static void MultiTest(){
		Thread t=new Thread(new Runnable(){
			public void run(){
				SingleThreadSingleton t1 = SingleThreadSingleton.getInstance();
				System.out.println(t1);
			}
		});
		Thread v=new Thread(new Runnable(){
			public void run(){
				SingleThreadSingleton t2 = SingleThreadSingleton.getInstance();
				System.out.println(t2);
			}
		});
		t.start();
		v.start();

	}
}

// static instance=new Singleton();则多线程也安全
class SingleThreadSingleton{
	private SingleThreadSingleton(){
	}
	//创建时就初始化可能很耗时
	//private static SingleThreadSingleton instance = new SingleThreadSingleton();
	private static SingleThreadSingleton instance = null;
	public static SingleThreadSingleton getInstance(){
		if(instance==null){//多线程这里容易出问题
			instance = new SingleThreadSingleton();
		}
		return instance;
	}

}