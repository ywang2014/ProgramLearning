/**
	快速排序的切分思想
	
	找到第k小的元素
*/
public static Comparable select(Comparable[] a, int k){
	StdRandom.shuffle(a);
	int lo = 0;
	int hi = a.length - 1;
	while (hi > lo){
		int j = partition(a, lo, hi);
		if (j == k){
			break;
		}
		else if (j < k){
			lo = j + 1;
		}
		else if (j > k){
			hi = j - 1;
		}
	}
	return a[k];
}