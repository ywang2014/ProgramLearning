/**
	最大子序列求和
	
	扫描算法
	时间复杂度：O(n)
*/
int maxSequence(int *arr, int l, int u){
	int maxSum = 0;
	int maxEndingHere = 0;	// 记录index到达i处时，子序列的所有和的值，或者0.
	
	for (int i = 0; i < n; i++){
		maxEndingHere = max(maxEndingHere + arr[i], 0);	// 和小于0，则不再相加了，直接舍弃，重新开始求和
		maxSum = max(maxSum, maxEndingHere);
	}
	
	return maxSum;
}


/*********************** 版本二 **********************************/
int maxSequence(int *arr, int l, int u){
	int maxSum = 0;
	
	for (int i = 1; i < n; i++){
		arr[i] = max(arr[i], arr[i] + arr[i-1]);	// 修改了原始数组
		maxSum = max(maxSum, arr[i]);
	}
	
	return maxSum;
}
