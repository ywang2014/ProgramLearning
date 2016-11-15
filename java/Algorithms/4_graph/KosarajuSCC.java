/**
	有向图中强连通分量的Kosaraju算法
*/
public class KosarajuSCC{
	private boolean[] marked;
	private int[] id;
	private int count;
	
	public KosarajuSCC(Digraph g){
		marked = new boolean[g.V()];
		id = new int[g.V()];
		DepthFirstOrder order = new DepthFirstOrder(g.reverse());
		for (int s : order.reversePost()){	// ???
			if (!marked[s]){
				dfs(g, s);
				count++;
			}
		}
	}
	
	private void dfs(Digraph g, int v){
		marked[v] = true;
		id[v] = count;
		for (int w : g.adj(v)){
			if (!marked[w]){
				dfs(g, w);
			}
		}
	}
	
	public boolean stronglyConnented(int v, int w){
		return id[v] == id[w];
	}
	
	public int id(int v){
		return id[v];
	}
	
	public int count(){
		return count;
	}
}