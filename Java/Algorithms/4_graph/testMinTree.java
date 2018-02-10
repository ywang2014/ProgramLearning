/**
	最小生成树的测试用例
*/
public static void main(String[] args){
	In in = new In(args[0]);
	EdgeWeightedGraph g;
	g = new EdgeWeighedGraph(in);
	
	MST mst = new MST(g);
	for (Edge e : mst.edges()){
		StdOut.println(e);
	}
	StdOut.println(mst.weight());
}