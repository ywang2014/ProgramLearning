/**
	Bellman-Ford算法中的放松操作
*/
private void relax(EdgeWeightedDigraph g, int v){
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
		if (cost++ % g.V() == 0){
			findNegativeCycle();
		}
	}
}