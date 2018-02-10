/**
	寻找有向环
*/
public class DirectedCycle{
	private boolean[] marked;
	private int[] edgeTo;
	private Stack<Integer> cycle;
	private boolean[] onStack;
	
	public DirectedCycle(Digraph g){
		onStack = new boolean[g.V()];
		edgeTo = new int[g.V()];
		marked = new boolean[g.V()];
		for (int v = 0; v < g.V(); v++){
			if (!marked[v]){
				dfs(g, v);
			}
		}
	}
	
	private void dfs(Digraph g, int v){
		onStack[v] = true;
		marked[v] = true;
		for (int w : g.adj(v)){
			if (this.hasCycle()){
				return ;
			}
			else if (!marked[w]){
				edgeTo[w] = v;
				dfs(g, w);
			}
			else if (onStack[w]){	// ??? 存在环，for循环，第一步就是检查环，所以此处不需要return。
				cycle = new Stack<Integer>();
				for (int x = v; x != w; x = edgeTo[x]){
					cycle.push(x);
				}
				cycle.push(w);
				cycle.push(v)
			}
		}
		onStack[v] = false;
	}
	
	public boolean hasCycle(){
		return cycle != null;
	}
	
	public Iterable<Integer> cycle(){
		return cycle;
	}
}