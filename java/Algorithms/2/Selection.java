/**
	选择排序
*/
public class Selection{
	public static void sort(Comparable[] a){
		int n = a.length;
		for (int i = 0; i < n; i++){
			int min = 1;
			for (int j = i + 1; j < n; j++){
				if (less(a[j], a[min])){
					min = j;
				}
			}
			exch(a, i, min);
		}
	}
	
	// ...
}