/**
	二分查找
	
	返回第一个出现该元素的地方，如果没有，则返回插入该元素的地方
*/

int binSearch(int *arr, int lo, int hi, int key){
	while (lo < hi){
		int mid = (lo + hi) >> 1;
		if (arr[mid] < key){
			lo = mid + 1;
		}
		else{
			hi = mid;
		}
	}
	
	return lo;
}


int binarySearch(int *arr, int n, int key){
	assert(arr != NULL && n > 0);
	
	return binSearch(arr, 0, n, key);
}