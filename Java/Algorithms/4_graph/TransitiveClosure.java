/**
	有向图顶点可达性 -- 传递闭包
*/
public class TransitiveClosure{
	private DirectedDFS[] all;
	
	TransitiveClosure(Digraph g){
		all = new DirectedDFS[g.V()];
		for (int v = 0; v < g.V(); v++){
			all[v] = new DirectedDFS(g, v);
		}
	}
	
	boolean reachable(int v, int w){
		return all[v].marked(w);
	}
}