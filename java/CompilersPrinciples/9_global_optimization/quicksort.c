/**
	快速排序代码
*/
void quicksort(int m, int n){
	// 递归地对a[m],a[n]之间的元素排序
	int i, j;
	int v, x;
	if (n <= m){
		return ;
	}
	i = m -1;
	j = n;
	v = a[n];
	while (1){
		do
			i = i + 1;
		while (a[i] < v);
		do
			j = j - 1;
		while (a[j] > v);
		if (i >= j){
			break;
		}
		x = a[i];
		a[i] = a[j];
		a[j] = x;
	}
	x = a[i];
	a[i] = a[n];
	a[n] = x;
	
	quicksort(m, j);
	quicksort(i+1, n);
}