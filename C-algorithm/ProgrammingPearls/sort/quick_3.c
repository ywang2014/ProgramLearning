/**
	快速排序
	
	解决已排序好的数组，进行排序的情况
*/
void qsort(int *arr, int lo, int hi){
	if (lo >= hi){
		return ;
	}
	
	swap(arr[lo], randint(lo, hi));
	int arr_lo = arr[lo];
	int i = lo;
	int j = hi + 1;
	while (1){
		// i++;
		// while (i <= hi && arr[i] < arr_lo){
			// i++;
		// }
		// j--;
		// while (arr[j] > arr_lo){
			// j--;
		// }
		while (++i <= hi && arr[i] < arr_lo);
		while (arr[--j] > arr_lo);
		if (i > j){
			break;
		}
		swap(arr[i], arr[j]);
	}
	swap(arr[lo], arr[j]);
	
	qsort(arr, lo, j-1);
	qsort(arr, j+1, hi);
}

int randint(int lo, int hi){
	unsigned int seed = time();
	srand(seed);
	
	return lo + rand() % (hi - lo + 1);
}