/**
	三向切分的快速排序
*/
public class Quick3way{
	private static void sort(Comparable[] a, int lo, int hi){
		if (hi <= lo){
			return ;
		}
		int small = lo;
		int i = lo + 1;
		int big = hi;
		Comparable value = a[lo];
		
		while (i <= big){
			// deal with a data then i++ every time. 
			// if less data then small++
			// if biger data then big-- but i should not ++.
			int cmp = a[i].compareTo(value);
			if (cmp < 0){
				exch(a, small++, i++);
			}
			else if (cmp == 0){
				i++;
			}
			else{
				exch(a, i, big--);	// i should not ++, because a[i] is not ordered
			}
		}
		sort(a, lo, small - 1);
		sort(a, big + 1, hi);
	}
}