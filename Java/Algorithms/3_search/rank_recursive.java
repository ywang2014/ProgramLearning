/**
	递归的二分查找
*/
public int rank(Key k, int lo, int hi){
	if (lo > hi){
		return lo;
	}
	int mid = (hi - lo) / 2 + lo;
	int cmp = key.compareTo(keys[mid]);
	if (cmp < 0){
		return rank(key, lo, mid - 1);
	}
	else if (cmp > 0){
		return rank(key, mid + 1, hi);
	}
	else{
		return mid;
	}
}