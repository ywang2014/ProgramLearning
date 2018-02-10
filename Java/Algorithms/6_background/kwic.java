/**
	上下文中的关键字搜索 keyword in context
*/
public class KWIC{
	public static void main(String[] args){
		In in = new In(args[0]);
		int context = Integer.parseInt(args[1]);
		
		String text = in.readAll().replaceAll("\\s+", " ");
		int N = text.length();
		SuffixArray sa = new SuffixArray(text);
		
		while (StdIn.hasNextLine()){
			String q = StdIn.readLine();
			for (int i = sa.rank(q); i < N && sa.select(i).startsWith(q); i++){
				int from = Math.max(0, sa.index(i) - context);
				int to = Math.min(N-1, from + q.length() + 2 * context);
				StdOut.println(text.subString(from, to));
			}
			StdOut.println();
		}
	}
}