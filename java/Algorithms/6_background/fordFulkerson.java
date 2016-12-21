/**
	最短增广路径的Ford-Fulkerson最大流量算法
*/
public class FordFulkerson{
	private boolean[] marked;
	private FlowEdge[] edgeTo;
	private double value;
	
	public FordFulkerson(FlowNetwork g, int s, int t){
		while (hasAugmentingPath(g, s, t)){
			double bottle = Double.POSITIVE_INFINTY;
			for (int v = t; v != s; v = edgeTo[v].other(v)){
				bottle = Math.min(bottle, edgeTo[v]..residualCapacityTo(v));
			}
			for (int v = t; v != s; v = edgeTo[v].other(v)){
				edgeTo[v].addResidualFlowTo(v, bottle);
			}
			value += bottle;
		}
	}
	
	public double value(){
		return value;
	}
	
	public boolean inCut(int v){
		return marked[v];
	}
	
	public static void main(String[] args){
		FlowNetwork g = new FlowNetwork(new In(args[0]));
		int s = 0;
		int t = g.V() - 1;
		FordFulkerson maxflow = new FordFulkerson(g, s, t);
		
		StdOut.println("Max flow from " + s + " to " + t);
		for (int v = 0; v < g.V(); v++){
			for (FlowEdge e : g.adj(v)){
				if ((v == e.from()) && e.flow() > 0){
					StdOut.println(" " + e);
				}
			}
		}
		StdOut.println("Max flow value = " + maxflow.value());
	}
}