/**
	任意顶点对之间的最短路径
*/
public class DijkstraAllPairsSP{
	private DijkstraSP[] all;
	
	DijkstraAllPairsSP(EdgeWeightedDigraph g){
		all = new DijkstraSP[g.V()];
		for (int v = 0; v < g.V(); v++){
			all[v] = new DijkstraSP(g, v);
		}
	}
	
	Iterable<Edge> path(int s, int t){
		return all[s].pathTo(t);
	}
	
	double dist(int s, int v){
		return all[s].distTo(v);
	}
}