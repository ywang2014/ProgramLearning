/**
	使用NFA模拟的模式匹配
*/
public boolean recognizes(String txt){
	Bag<Integer> pc = new Bag<Integer>();
	DirectedDFS dfs = new DirectedDFS(g, 0);	// g?  起点可达
	for (int v = 0; v < g.V(); v++){
		if (dfs.marked(v)){
			pc.add(v);
		}
	}
	
	for (int i = 0; i < txt.length(); i++){
		Bag<Integer> match = new Bag<Integer>();
		for (int v : pc){
			if (v < M){
				if (re[v] == txt.charAt(i) || re[v] == '.'){
					match.add(v+1);
				}
			}
		}
		pc = new Bag<Integer>();
		dfs = new DirectedDFS(g, match);	// 多点可达
		for (int v = 0; v < G.V(); v++){
			if (dfs.marked(v)){
				pc.add(v);
			}
		}
	}
	
	for (int v : pc){
		if (v == M){
			return true;
		}
	}
	return false;
}
