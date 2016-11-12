/**
	判断图是否有环
*/
public class Cycle{
	private boolean[] marked;
	private boolean hasCycle;
	
	public Cycle(Graph g){
		marked = new boolean[g.V()];
		for (int s = 0; s < g.V(); s++){
			if (!marked[s]){
				dfs(g, s, s);
			}
		}
	}
	
	private void dfs(Graph g, int v, int u){
		marked[v] = true;
		for (int w : g.adj(v)){
			if (!marked[w]){
				dfs(g, w, v);
			}
			else if (w != u){	// w==u 则表示(w->v, v->w)的同一条边，不等则说明，其他边可以回去。
				hasCycle = true;
			}
		}
	}
	
	public boolean hasCycle(){
		return hasCycle;
	}
}