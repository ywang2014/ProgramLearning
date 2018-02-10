/**
	Dedup 过滤器
*/
public class Dedup{
	public static void main(String[] args){
		 HashSet<String> set;
		 set = new HashSet<String>();
		 while (!StdIn.isEmpty()){
			 String key = StdIn.readString();
			 if (!set.contains(key)){
				 set.add(key);
				 StdOut.println(key);
			 }
		 }
	}
}