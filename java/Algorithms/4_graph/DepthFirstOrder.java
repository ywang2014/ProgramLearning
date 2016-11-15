/**
	有向图中，基于深度优先搜索的顶点排序
*/
public class DepthFirstOrder{
	private boolean[] marked;
	private Queue<Integer> pre;
	private Queue<Integer> post;
	private Stack<Integer> reversePost;
	
	public DepthFirstOrder(Digraph g){
		pre = new Queue<Integer>();
		post = new Queue<Integer>();
		reversePost = new Stack<Integer>();
		marked = new boolean[g.V()];
		
		for (int v = 0; v < g.V(); v++){
			if (!marked[v]){
				dfs(g, v);
			}
		}
	}
	
	private void dfs(Digraph g, int v){
		pre.enqueue(v);
		marked[v] = true;
		for (int w : g.adj(v)){
			if (!marked[w]){
				dfs(g, w);
			}
		}
		post.enqueue(v);
		reversePost.push(v);
	}
	
	public Iterable<Integer> pre(){
		return pre;
	}
	
	public Iterable<Integer> post(){
		return post;
	}
	
	public Iterable<Integer> reversePost(){
		return reversePost;
	}
}