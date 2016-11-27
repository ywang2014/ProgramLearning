public class DijkstraSP{
	private DirectedEdge[] edgeTo;
	private double[] distTo;
	private IndexMinPQ<Double> pq;
	
	public DijkstraSP(EdgeWeightedDigraph g, int s){
		edgeTo = new DirectedEdge[g.V()];
		distTo = new double[g.V()];
		pq = new IndexMinPQ<Double>(g.V());
		for (int v = 0; v < g.V(); v++){
			distTo[v] = Double.POSITIVE_INFINITY;
		}
		distTo[s] = 0.0;
		pq.insert(s, 0.0);
		while (!pq.isEmpty()){
			relax(g, pq.delMin())
		}
	}
	
	private void relax(EdgeweightedDigraph g, int v){
		for (DirectedEdge e : g.adj(v)){
			int w = e.to();
			if (distTo[w] > distTo[v] + e.weight()){
				distTo[w] = distTo[v] + e.weight();
				edgeTo[w] = e;
				if (pq.contains(w)){
					pq.change(w, distTo[w]);
				}
				else{
					pq.insert(w, distTo[w]);
				}
			}
		}
	}
	
	public double distTo(int v){
		return distTo[v];
	}
	
	public boolean hasPathTo(int v){
		return edgeTo[v] != null;
	}
	
	public Iterable<Edge> pathTo(int v){
		// TODO
	}
}