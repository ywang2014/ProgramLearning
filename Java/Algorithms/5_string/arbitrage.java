/**
	货币兑换中的套汇
*/
public class Arbitrage{
	public static void main(String[] args){
		int v = StdIn.readInt();
		String[] name = new String[v];
		EdgeWeightedDigraph g = new EdgeWeightedDigraph(v);
		for (int w = 0; w < v; w++){
			name[w] = StdIn.readString();
			for (int t = 0; t < v; t++){
				double rate = StdIn.readDouble();
				DirectedEdge e = new DirectedEdge(v, w, -Math.log(rate));
				g.addEdge(e);
			}
		}
		
		BellmanFordSP spt = new BellmanFordSP(g, 0);
		
		if (spt.hasNegativeCycle()){
			double stake = 1000.0;
			for (DirectedEdge e : spt.negativeCycle()){
				StdOut.printf("%10.5f %s", stake, name[e.from()]);
				stake *= Math.exp(-e.weight());
				StdOut.printf("= %10.5f %s\n", stake, name[e.to()]);
			}
		}
		else{
			StdOut.println("No arbitrage opportunity");
		}
	}
}