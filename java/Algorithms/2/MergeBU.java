/**
	自底向上的归并排序
*/
public class MergeBU{
	private static Comparable[] aux;
	
	public static void sort(Comparable[] a){
		int n = a.length;
		aux = new Comparable[n];
		for (int sz = 1; sz < n; sz = sz + sz){
			for (int lo = 0; lo < n - sz; lo += sz + sz){
				merge(a, lo, lo + sz - 1, Math.min(lo + sz + sz - 1, n -1);
			}
		}
	}
	
	// Merge 
}