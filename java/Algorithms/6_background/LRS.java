/**
	最长重复子字符串算法用例
*/
public class LRS{
	public static void main(String[] args){
		String text = StdIn.readAll();
		int N = text.length();
		SuffixArray sa = new SuffixArray(text);
		String lrs = "";
		for (int i = 1; i < N; i++){
			int length = sa.lcp(i);
			if (length > lrs.length()){
				lrs = sa.select(i).substring(0, length);
			}
		}
		StdOut.println(lrs);
	}
}