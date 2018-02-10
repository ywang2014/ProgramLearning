/**
	深度优先搜索算法
*/
void search(n){
	visited(n);
	for (s in back(n)){
		if (isUnvisited(s)){
			T.add(n, s);	// 添加边n-->s到树T中
			search(s);
		}
	}
	dfn[n] = c;
	c = c - 1;
}

main(){
	T = null;
	for (n in G.node()){
		unvisited(n);
	}
	c = G.num();
	search(n0);
}