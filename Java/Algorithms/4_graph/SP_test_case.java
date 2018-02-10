/**
	最短路径测试用例
*/
public class void main(String[] args){
	EdgeWeightedDigraph g;
	g = new EdgeWeightedDigraph(new In(args[0]));
	int s = Integer.parseInt(args[1]);
	SP sp = new SP(g, s);
	
	for (int t = 0; t < g.V(); t++){
		StdOut.print(s + " to " + t);
		StdOut.printf(" (%4.2f): ", sp.distTo(t));
		if (sp.hasPathTo(t)){
			for (DirectedEdge e : sp.pathTo(t)){
				StdOut.print(e + " ");
			}
		}
		StdOut.println();
	}
}