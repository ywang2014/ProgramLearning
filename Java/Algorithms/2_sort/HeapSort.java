/**
	堆排序
*/
public static void sort(Comparable[] a){
	int N = a.length;
	for (int i = N / 2; i > 0; i--){
		sink(a, i, N);
	}
	while (N > 1){
		exch(a, 1, N--);
		sink(a, 1, N);
	}
}