/**
	队列 FIFO
*/
public class Queue<Item> implements Iterable<Item>{
	public Queue();
	public void enqueque(Item elem);
	public Item dequeue();
	public boolean isEmpty();
	public int size();
}

// 队列的应用
public static int[] readInts(String name){
	In in = new In(name);
	Queue<Integer> q = new Queue<Integer>();
	while (!in.isEmpty()){
		q.enqueue(in.readInt());
	}
	int N = q.size();
	int[] a = new int[N];
	for (int i = 0; i < N; i++){
		a[i] = q.dequeue();
	}
	
	return a;
}