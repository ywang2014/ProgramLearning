/**
	拓扑排序
*/
public class Topological{
	private Iterable<Integer> order;
	
	public Topological(Digraph g){
		DirectedCycle cyclefinder = new DirectedCycle(g);
		if (!cyclefinder.hashCycle()){
			DepthFirstOrder dfs = new DepthFirstOrder(g);
			order = dfs.reversePost();
		}
	}
	
	public Iterable<Integer> order(){
		return order;
	}
	
	public boolean isDAG(){
		return order != null;
	}
	
	public static void main(String[] args){
		String filename = args[0];
		String separator = args[1];
		SymbolDigraph sg = new SymbolDigraph(filename, separator);
		
		Topological top = new Topological(sg.G());
		for (int v : top.order()){
			StdOut.println(sg.name(v));
		}
	}
}