/**
	最长路径长度
*/
public class LongestPath{
	private boolean[] marked;
	private int max;
	
	public LongestPath(Graph g, int s, int t){
		marked = new boolean[g.V()];
		dfs(g, s, t, 0);
	}
	
	private void dfs(Graph g, int v, int t, int i){
		if (v == t && i > max){
			max = i;
		}
		if (v == t){
			return ;
		}
		marked[v] = true;
		for (int w : g.adj(v)){
			if (!marked[w]){
				dfs(g, w, t, i+1);
			}
		}
		marked[v] = false;
	}
	
	public int maxLength(){
		return max;
	}
}