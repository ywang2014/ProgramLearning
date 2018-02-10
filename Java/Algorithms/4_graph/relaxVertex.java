/**
	顶点的松弛
*/
private void relax(EdgeWeightedDigraph g, int v){
	for (DirectedEdge e : g.adj(v)){
		int w = e.to();
		if (distTo[w] > distTo[v] + e.weight()){
			distTo[w] = distTo[v] + e.weight();
			edgeTo[w] = e;
		}
	}
}