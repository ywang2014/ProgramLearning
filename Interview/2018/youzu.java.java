/**
	游族面试：
		线程安全的单例模式
*/
public class Singleton{
	private static volatile Singleton instance = null;
	
	private Singleton(){
		// default constructor
	}
	
	public static Singleton getInstance(){
		if (this.instance == null){
			return newInstance();
		}
		return this.instance;
	}
	
	public synchronized static Singleton newInstance(){
		if (this.instance == null){
			this.instance = new Singleton();
		}
		return this.instance;
	}
}