/**
	加权有向边的数据类型
*/
public class DirectedEdge{
	private final int V;
	private final int W;
	private final double WEIGHT;
	
	public DirectedEdge(int v, int w, double weight){
		this.V = v;
		this.W = w;
		this.weight = weight;
	}
	
	public double weight(){
		return WEIGHT;
	}
	
	public int from(){
		return V;
	}
	
	public int to(){
		return W;
	}
	
	public String toString(){
		return String.format("%d->%d %.2f", V, W, WEIGHT);
	}
}