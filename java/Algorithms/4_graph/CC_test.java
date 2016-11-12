/**
	查找连通分量API的测试用例
*/

public static void main(String[] args){
	Graph g = new Graph(new In(args[0]));
	CC c = new CC(g);
	
	int m = cc.count;
	StdOut.println(m + " components");
	
	Bag<Integer>[] components;
	components = (Bag<integer>[]) new Bag[m];
	for (int i = 0; i < m; i++){
		components[i] = new Bag<Integer>();
	}
	for (int v = 0; v < G.v(); v++){
		components[cc.id(v)].add(v);
	}
	for (int i = 0; i < m; i++){
		for (int v : components[i]){
			StdOut.print(v + " ");
		}
		StdOut.println();
	}
}