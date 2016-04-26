/**
	最大子序列求和
	
	时间复杂度：O(nlog(n))
*/

int maxSequence(int *arr, int l, int u){
	if (l > u){
		return 0;	// 没有元素
	}
	if (l == u){
		return max(0, arr[l]);	// 一个元素，负数返回0.
	}
	
	int mid = (l + u) / 2;
	int l_max = 0;
	int sum = 0;
	for (int i = mid; i >= l; i--){		// 必须中间往两边计算
		sum += arr[i];
		l_max = max(l_max, sum);
	}
	
	int r_max = 0;
	sum = 0;
	for (int i = mid + 1; i <= u; i++){
		sum += arr[i];
		r_max = max(r_max, sum);
	}
	
	return max(l_max + r_max, maxSequence(arr, l, mid), maxSequence(arr, mid+1, u));
}

/***************** 改进版 ************/
// 区间 [l, u)
int maxSequence(int *arr, int l, int u){
	if (l == u){
		return 0;	// 没有元素
	}
	else if (l == u - 1){
		return max(0, arr[l]);	// 一个元素，负数返回0.
	}
	
	int mid = (l + u) / 2;
	int l_max = maxSequence(arr, l, mid);
	int r_max = maxSequence(arr, mid, u);
	
	int cur_max = 0;
	int sum = 0;
	for (int i = mid - 1; i >= l; i--){
		sum += arr[i];
		cur_max = max(cur_max, sum);
	}
	
	sum = cur_max;
	for (int i = mid; i < u; i++){
		sum += arr[i];
		cur_max = max(cur_max, sum);
	}
	
	return max(l_max, r_max, cur_max);
}