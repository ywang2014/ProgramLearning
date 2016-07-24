/**
	使用比较器实现优先队列
*/
import java.util.Comparator;

public class Transaction{
	...
	private final String who;
	private final Date when;
	private final double amount;
	...
	
	/*
		Java里面static一般用来修饰成员变量或函数。但有一种特殊用法是用static修饰内部类，普通类是不允许声明为静态的，
		只有内部类才可以。被static修饰的内部类可以直接作为一个普通类来使用，而不需实例一个外部类
	*/
	public static class WhoOrder implements Comparator<Transaction>{
		public int compare(Transaction v, Transaction w){
			return v.who.compareTo(w.who);
		}
	}
	
	public static class WhenOrder implements Comparator<Transaction>{
		public int compare(Transaction v, Transaction w){
			return v.when.compareTo(w.when);
		}
	}
	
	public static class HowMuchOrder implements Comparator<Transaction>{
		public int compare(Transaction v, Transaction w){
			if (v.amount < w.amount){
				return -1;
			}
			else if (v.amount > w.amount){
				return 1;
			}
			return 0;
		}
	}
}