/**
	加权有向图的数据类型
*/
public class EdgeWeightedDigraph{
	private final int V;
	private int E;
	private Bag<DirectedEdge>[] adj;
	
	public EdgeWeightedDigraph(int v){
		this.V = v;
		this.E = 0;
		adj = (Bag<DirectedEdge>[]) new Bag[v];
		for (int w = 0; w < V; w++){
			adj[w] = new Bag<DirectedEdge>();
		}
	}
	
	public EdgeWeightedDigraph(In in){
		// TODO
	}
	
	public int V(){
		return V;
	}
	
	public int E(){
		return E;
	}
	
	public void addEdge(DirectedEdge e){
		adj[e.from()].add(e);
		E++;
	}
	
	public Iterable<Edge> adj(int v){
		return adj[v];
	}
	
	public Iterable<DirectedEdge> edges(){
		Bag<DirectedEdge> bag = new Bag<DirectedEdge>();
		for (int v = 0; v < V; v++){
			for (DirectedEdge e : adj[v]){
				bag.add(e);
			}
		}
		return bag;
	}
}