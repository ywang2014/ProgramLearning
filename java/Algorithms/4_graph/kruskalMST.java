/**
	最小生成树的Kruskal算法
*/
public class KruskalMST{
	private Queue<Edge> mst;
	public KruskalMST(EdgeWeightedGraph g){
		mst = new Queue<Edge>();
		MinPQ<Edge> pq = new MinPQ<Edge>(g.edges());
		UF uf = new UF(g.V());
		
		while (!pq.isEmpty() && mst.size() < (g.V() - 1)){
			Edge e = pq.delMin();
			int v = e.either();
			int w = e.other(v);
			if (uf.connected(v, w)){
				continue;
			}
			uf.union(v, w);
			mst.enqueue(e);
		}
	}
	
	public Iterable<Edge> edges(){
		return mst;
	}
	
	public double weight(){
		// TODO
	}
}