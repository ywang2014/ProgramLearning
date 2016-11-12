public class TestSearch{
	public static void main(String[] args){
		Graph g = new Graph(new In(args[0]));
		int s = Integer.parseInt(args[1]);
		Search search = new Search(g, s);
		
		for (int v = 0; v < g.V(); v++){
			if (search.marked(v)){
				StdOut.print(v + " ");
			}
		}
		StdOut.println();
		if (search.count() != g.V()){
			StdOut.print("NOT ");
		}
		StdOut.println("connected");
	}
}