/**
	递归实现二分查找
*/
public static int rank(int key, int[] arr){
	return rank(key, arr, 0, arr.length);
}

// 大于数组最大值的元素的返回值超出了数组的界，返回该元素插入数组的位置！
public static int rank(int key, int[] arr, int lo, int hi){
	if (lo == hi){
		return lo;
	}
	
	int mid = (lo + hi) / 2;	// 可能溢出，lo + (hi - lo) / 2 不会有溢出的危险
	if (arr[mid] < key){
		return rank(key, arr, mid+1, hi);
	}
	else{
		return rank(key, arr, lo, mid);
	}
}