/**
	白名单过滤器 -- 黑名单过滤器
*/
public class WhiteFilter{
	public static void main(String[] args){
		HashSet<String> set;
		set = new HashSet<String>();
		In in = new In(args[0]);
		while (!in.isEmpty()){
			set.add(in.readString());
		}
		while (!StdIn.isEmpty()){
			String word = StdIn.readString();
			if (set.contains(word)){
				StdOut.println(word);
			}
		}
	}
}