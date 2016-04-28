/**
	快速排序
	
	小数组使用插入排序，性能更好
*/
void qsort_4(int *arr, int lo, int hi, int cutoff){
	if (hi - lo < cutoff){
		return ;
	}
	
	swap(arr[lo], randint(lo, hi));
	int arr_lo = arr[lo];
	int i = lo;
	int j = hi + 1;
	while (1){
		while (++i <= hi && arr[i] < arr_lo);
		while (arr[--j] > arr_lo);
		if (i > j){
			break;
		}
		swap(arr[i], arr[j]);
	}
	swap(arr[lo], arr[j]);
	
	qsort_4(arr, lo, j-1, cutoff);
	qsort_4(arr, j+1, hi, cutoff);
}

// 对外接口
void qsort(int *arr, int n){
	if (arr == NULL || n < 1){
		return ;
	}
	
	qsort_4(arr, 0, n - 1, 10);
	
	for (int i = 1; i < n; i++){
		int temp = arr[i];
		for (int j = i; j > 0 && arr[j] < arr[j-1]; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}


int randint(int lo, int hi){
	unsigned int seed = time();
	srand(seed);
	
	return lo + rand() % (hi - lo + 1);
}