/**
	希尔排序
	
	递增序列：(3^k - 1)/2	1,4,13,40...
*/
public class Shell{
	public static void sort(Comparable[] a){
		int n = a.length;
		int h = 1;
		while (h < n / 3){
			h = 3 * h + 1;
		}
		while (h >= 1){
			for (int i = h; i < n; i++){
				for (int j = i; j >= h && less(a[j], a[j-h]); j -= h){
					exch(a, j, j-h);
				}
			}
			h = h / 3;
		}
	}
	
	// ...
}