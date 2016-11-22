/**
	最小生成树的Prim算法的延时实现
*/
public class LazyPrimMST{
	private boolean[] marked;
	private Queue<Edge> mst;
	private MinPQ<Edge> pq;
	
	public LazyPrimMST(EdgeWeightedGraph g){
		pq = new MinPQ<Edge>();
		marked = new boolean[g.V()];
		mst = new Queue<Edge>();
		
		visit(g, 0);
		while (!pq.isEmpty()){
			Edge e = pq.delMin();
			int v = e.either();
			int w = e.other(v);
			if (marked[v] && marked[w]){
				continue;	// 过滤无效的边
			}
			
			mst.enqueue(e);
			
			// 不可能同时发生的
			if (!marked[v]){
				visit(g, v);
			}
			if (!marked[w]){
				visit(g, w);
			}
		}
	}
	
	private void visit(EdgeWeightedGraph g, int v){
		marked[v] = true;
		for (Edge e : g.adj(v)){
			if (!marked[e.other(v)]){
				pq.insert(e);
			}
		}
	}
	
	public Iterable<Edge> edges(){
		return mst;
	}
	
	public double weight(){
		// TODO
	}
}