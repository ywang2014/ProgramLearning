/**
	Union-find算法的实现
	
	quick find
*/
public class UnionFind{
	private int[] id;
	private int count;
	
	public UnionFind(int n){
		id = new int[n];
		for (int i = 0; i < n; i++){
			id[i] = i;
		}
		count = n;
	}
	
	public int count(){
		return count;
	}
	
	public boolean connected(int p, int q){
		return find(p) == find(q);
	}
	
	public int find(int p){
		return id[p];
	}
	
	public void union(int p, int q){
		int parent_p = find(p);
		int parent_q = find(q) ;
		
		if (parent_p < parent_q){
			for (int i = 0; i < id.length; i++){
				if (find(i) == parent_q){
					id[i] = parent_p;
				}
			}
		}
		else if (parent_p > parent_q){
			for (int i = 0; i < id.length; i++){
				if (find(i) == parent_p){
					id[i] = parent_q;
				}
			}
		}
		count--;
	}
	
	public static void man(String[] args){
		int n = StdIn.readInt();
		UnionFind uf = new UnionFind(n);
		while (!StdIn.isEmpty()){
			int p = StdIn.readInt();
			int q = StdIn.readInt();
			if (uf.connected(p, q)){
				continue;
			}
			uf.union(p, q);
			StdOut.println(p + " " + q);
		}
		StdOut.println(uf.count() + "components");
	}
}