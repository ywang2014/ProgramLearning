/**
	无环加权有向图的最短路径算法
*/
public class AcyclicSP{
	private DirectedEdge[] edgeTo;
	private double[] distTo;
	
	public AcyclicSP(EdgeWeightedDigraph g, int s){
		edgeTo = new DirectedEdge[g.V()];
		distTo = new double[g.V()];
		
		for (int v = 0; v < g.V(); v++){
			distTo[v] = Double.POSITIVE_INFINITY;
		}
		distTo[s] = 0.0;
		
		Topological top = new Topological(g);
		for (int v : top.order()){
			relax(g, v);
		}
	}
	
	private void relax(EdgeWeightedDigraph g, int v){
		// TODO
	}
	
	public double distTo(int v){
		//
	}
	
	public boolean hasPathTo(int v){
		//
	}
	
	public Iterable<DirectedEdge> pathTo(int v){
		//
	}
}