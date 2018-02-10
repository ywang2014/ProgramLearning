/**
	图处理的常用算法
*/
public static int degree(Graph g, int v){
	int degree = 0;
	for (int w : g.adj(v)){
		degree++;
	}
	return degree;
}

public static int maxDegree(Graph g){
	int max = 0;
	for (int v = 0; v < g.V(); v++){
		int deg = degree(g, v);
		if (deg > max){
			max = deg;
		}
	}
	return max;
}

public static double avgDegree(Graph g){
	return 2 * g.E() / g.V();
}

public static int numberOfSelfLoops(Graph g){
	int count = 0;
	for (int v = 0; v < g.V(); v++){
		for (int w : g.adj()){
			if (v == w){
				count++;
			}
		}
	}
	return count / 2;
}

public String toString(){
	String s = V + " vertices, " + E + " edges\n";
	for (int v = 0; v < V; v++){
		s += v + ": ";
		for (int w : this.adj(v)){
			s += w + " ";
		}
		s += "\n";
	}
	return s;
}