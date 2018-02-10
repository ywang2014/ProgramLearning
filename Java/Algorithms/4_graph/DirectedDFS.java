/**
	有向图的可达性
*/
public class DirectedDFS{
	private boolean[] marked;
	
	public DirectedDFS(Digraph g, int s){
		marked = new boolean[g.V()];
		dfs(g, s);
	}
	
	public DirectedDFS(Digragh g, Iterable<Integer> sources){
		marked = new boolean[g.V()];
		for (int w : sources){
			if (!marked[s]){
				dfs(g, w);
			}
		}
	}
	
	private void dfs(Digraph g, int v){
		marked[v] = true;
		for (int w : g.adj(v)){
			if (!marked[w]){
				dfs(g, w);
			}
		}
	}
	
	public boolean marked(int v){
		return marked[v];
	}
	
	public static void main(String[] args){
		Digraph g = new Digraph(new In(args[0]));
		Bag<Integer> sources = new Bag<Integer>();
		for (int i = 1; i < args.length; i++){
			sources.add(Integer.parseInt(args[i]));
		}
		DirectedDFS reachable = new DirectedDFS(g, sources);
		for (int v = 0; v < g.V(); v++){
			if (reachable.marked(v)){
				StdOut.print(v + " ");
			}
		}
		StdOut.println();
	}
}