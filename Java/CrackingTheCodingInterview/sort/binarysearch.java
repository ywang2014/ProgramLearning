/**
	二分查找
*/
int binarysearch(int[] array, int x){
	int low = 0;
	int high = array.length - 1;
	int mid;
	
	while (low <= high){
		mid = (low + high) / 2;
		if (array[low] < x){
			low = mid + 1;
		}
		else if (array[mid] > x){
			high = mid - 1;
		}
		else{
			return mid;
		}
	}
	
	return -1;
}

// 递归版
int binarysearchRecursive(int[] array, int x, int low, int high){
	if (low > high){
		return -1;
	}
	else if (low == high){
		return array[low] == x ? low : -1;
	}
	
	int mid = (low + high) / 2;
	if (array[mid] < x){
		binarysearchRecursive(array, x, mid + 1, high);
	}
	else if (array[mid] > x){
		binarysearchRecursive(array, x, low, mid - 1);
	}
	else{
		return mid;
	}
}