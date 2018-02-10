/**
	基于队列的Bellman-Ford算法
*/
public class BellmanFordSP{
	private double[] distTo;
	private DirectedEdge[] edgeTo;
	private boolean[] onQ;
	private Queue<Integer> queue;
	private int cost;	// relax()调用次数
	private Iterable<DirectedEdge> cycle;
	
	public BellmanFordSP(EdgeWeightedDigraph g, int s){
		distTo = new double[g.V()];
		edgeTo = new DirectedEdge[g.V()];
		onQ = new boolean[g.V()];
		queue = new Queue<Integer>();
		for (int v = 0; v < g.V(); v++){
			distTo[v] = Double.POSITIVE_INFINITY;
		}
		distTo[s] = 0.0;
		queue.enqueue(s);
		onQ[s] = true;
		while (!queue.isEmpty() && !this.hasNegativeCycle()){
			int v = queue.dequeue();
			onQ[v] = false;
			relax(g, v);
		}
	}
	
	private void relax(EdgeWeightedDigraph g, int v){
		// TODO
		for (DirectedEdge e : g.adj(v)){
			int w = e.to();
			if (distTo[w] > distTo[v] + e.weight()){
				distTo[w] = distTo[v] + e.weight();
				edgeTo[w] = e;
				if (!onQ[w]){
					queue.enqueue(w);
					onQ[w] = true;
				}
			}
			if (cost++ % g.V() == 0){	// cost++  // 应该在for循环外面
				findNegativeCycle();
			}
		}
	}
	
	public double distTo(int v){
		//
		return distTo[v];
	}
	
	public boolean hasPathTo(int v){
		//
		return edgeTo[v] != null;
	}
	
	public Iterable<Edge> pathTo(int v){
		//
	}
	
	private void findNegativeCycle(){
		// TODO
		int v = edgeTo.length;
		EdgeWeightedDigraph spt;
		spt = new EdgeWeightedDigraph(v);
		for (int i = 0; i < v; i++){
			if (edgeTo[i] != null){
				spt.addEdge(edgeTo[i]);
			}
		}
		EdgeWeightedCycleFinder cf = new EdgeWeightedCycleFinder(spt);
		
		cycle = cf.cycle();
	}
	
	public boolean hasNegativeCycle(){
		return cycle != null;
	}
	
	public Iterable<Edge> negativeCycle(){
		// TODO
		return cycle;
	}
}