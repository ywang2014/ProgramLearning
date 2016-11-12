/**
	使用广度优先搜索查找图中的路径
*/
public class BreadthFirstPaths{
	private boolean[] marked;
	private int[] edgeTo;
	private final int s;
	
	public BreadthFirstPaths(Graph g, int s){
		marked = new boolean[g.V()];
		edgeTo = new int[g.V()];
		this.s = s;
		bfs(g, s);
	}
	
	private void bfs(Graph g, int s){
		Queue<Integer> queue = new Queue<Integer>();
		marked[s] = true;
		queue.enqueue(s);
		while (!queue.isEmpty()){
			int v = queue.dequeue();
			for (int w : g.adj(v)){
				if (!marked[w]){
					edgeTo[w] = v;
					marked[w] = true;
					queue.enqueue(w);
				}
			}
		}
	}
	
	public boolean hasPathTo(int v){
		return marked[v];
	}
	
	public Iterable<Integer> pathTo(int v){
		// TODO
	}
}