/**
	优先级队列的用例
*/
public class TopM{
	public static void main(String[] args){
		int m = Integer.parseInt(args[0]);
		MinPQ<Transaction> pq = new MinPQ<Transaction>(m + 1)；
		while (StdIn.hasNextLine()){
			pq.insert(new Transaction(StdIn.readLine()));
			if (pq.size() > M){
				pq.delMin();
			}
		}
		Stack<Transaction> stack = new Stack<Transaction>();
		while (!pd.isEmpty()){
			stack.push(pd.delMin());
		}
		for (Transaction t : stack){
			StdOut.println(t);
		}
	}
}