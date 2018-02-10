/**
	Union-find算法的实现
	加权quick union
*/
public class WeightedQuickUnionFind{
	private int[] id;
	private int[] sz;	// 各根节点所对应的分量的大小
	private int count;	// 连通分量的数量
	
	public WeightedQuickUnionFind(int n){
		id = new int[n];
		sz = new int[n];
		for (int i = 0; i < n; i++){
			id[i] = i;
			sz[i] = 1;
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
		
		if (sz[pRoot] < sz[qRoot]){
			id[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		}
		else{
			id[qRoot] = pRoot;
			sz[pRoot] += sz[qRoot];
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