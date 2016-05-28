/**
	Union-find算法的实习
	quick union
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
	
	private int find(int p){
		while (id[p] != p){
			p = id[p];
		}
		
		return p;
	}
	
	public void union(int p, int q){
		int pRoot = find(p);
		int qRoot = find(q);
		
		if (pRoot == qRoot){
			return ;
		}
		id[pRoot] = qRoot;
		
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