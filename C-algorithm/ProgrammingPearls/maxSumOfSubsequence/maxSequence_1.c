/**
	最大子序列求和
	
	时间复杂度：O(n^3)
*/

int maxSequence(int *arr, int n){
	int maxSum = 0;
	int currentSum = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j <= n; j++){	// 必须有等于号
			currentSum = 0;
			for (int k = i; k < j; k++){
				currentSum += arr[k];
			}
			if (maxSum < currentSum){
				maxSum = currentSum;
			}
		}
	}
	
	return maxSum;
}