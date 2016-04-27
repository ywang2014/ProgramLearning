/**
	二分查找
	
	改进的版本
	arr[-1], arr[n]
*/

int binarySearch(int *arr, int n, int t){
	int l = -1;
	int u = n;
	
	while ((l + 1) != u){
		int mid = (l + u) / 2;
		if (arr[mid] < t){
			l = mid;
		}
		else{
			u = mid;
		}
	}
	// assert l+1==u && arr[l]<t&&arr[u]>=t 
	int p = u;
	if (n <= p || arr[p] != t){
		p = -1;
	}
	
	return p;
}