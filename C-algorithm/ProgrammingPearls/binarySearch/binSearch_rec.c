/**
	二分查找算法：
	
	递归版本实现
*/
int binSearch(int *arr, int lo, int hi, int key){
	if (lo < hi){
		int mid = (lo + hi) >> 1;
		if (arr[mid] < key){
			return binSearch(arr, mid+1, hi, key);
		}
		else{
			return binSearch(arr, lo, mid, key);
		}
	}
	
	return lo;
}

int binarySearch(int *arr, int n, int key){
	assert(arr != NULL && n > 0);
	
	return binSearch(arr, 0, n, key);
}