/**
	快速排序
*/

void qsort(int *arr, int lo, int hi){
	if (lo >= hi){
		return ;	// 一个元素
	}
	
	int pivot = partition(arr, lo, hi);
	
	qsort(arr, lo, pivot - 1);
	qsort(arr, pivot + 1, hi);
}

/*****************************************************/
void qsort(int *arr, int lo, int hi){
	if (lo >= hi){
		return ;	// 一个元素
	}
	
	int mid = lo;
	for (int i = l + 1; i <= hi; i++){
		if (arr[i] < arr[lo]){
			swap(arr[i], arr[++mid]);	// mid != i 才需要交换，否则自身交换。
		}
	}
	swap(arr[lo], arr[mid]);
	
	qsort(arr, lo, pivot - 1);
	qsort(arr, pivot + 1, hi);
}