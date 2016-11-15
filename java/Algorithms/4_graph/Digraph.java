/**
	有向图
*/
public class Digraph{
	private final int V;
	private int e;
	private Bag<Integer>[] adj;
	
	public Digraph(int v){
		this.V = v;
		this.e = 0;
		adj = (Bag<Integer>[]) new Bag[V];
		for (int i = 0; i < v; i++){
			adj[i] = new Bag<Integer>();
		}
	}
	
	public int V(){
		return V;
	}
	
	public int E(){
		return e;
	}
	
	public void addEdge(int v, int w){
		adj[v].add(w);
		e++;
	}
	
	public Iterable<Integer> adj(int v){
		return adj[v];
	}
	
	public Digraph reverse(){
		Digraph R = new Digraph(V);
		for (int v = 0; v < V; v++){
			for (int w : adj(v)){
	   			R.addEdge(w, v);
			}
		}
		return R;
	}
	
}