/**
	加权无向图的数据类型
*/
public class EdgeWeightedGraph{
	private final int V;
	private final int E;
	private Bag<Edge>[] adj;
	
	public EdgeWeightedGraph(int v){
		this.V = v;
		this.E = 0;
		adj = (Bag<Edge>[]) new Bag[V];
		for (int w = 0; w < V; w++){
			adj[w] = new Bag<Edge>();
		}
	}
	
	public EdgeWeightedGraph(In in){
		//TODO
	}
	
	public int V(){
		return V;
	}
	
	public int E(){
		return E;
	}
	
	public void addEdge(Edge e){
		int v = e.either();
		int w = e.other(v);
		adj[v].add(e);
		adj[w].add(e);
		E++;		
	}
	
	public Iterable<Edge> adj(int v){
		return adj[v];
	}
	
	public Iterable<Edge> edges(){
		//TODO
	}
}