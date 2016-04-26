/**
	最大子序列求和
	
	时间复杂度：O(n^2)
*/

int maxSequence(int *arr, int n){
	int maxSum = 0;
	int currentSum = 0;
	
	for (int i = 0; i < n; i++){
		currentSum = 0;
		for (int j = i; j < n; j++){	// 必须有等于号
			currentSum += arr[j];
			if (maxSum < currentSum){
				maxSum = currentSum;
			}
		}
	}
	
	return maxSum;
}


/********************** 第二种方法 *********************/
int maxSequence(int *arr, int n){
	if (arr == NULL || n < 1){
		return -1;	// invalid arguments
	}
	
	int *cumarr = (int *)malloc(n * sizeof(int));
	cumarr[0] = arr[0];
	for (int i = 1; i < n; i++){
		cumarr[i] = cumarr[i-1] + arr[i];
	}	// partial_sum
	
	int maxSum = arr[0];
	int currentSum = 0;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			if (i == 0){
				currentSum = cumarr[j] - 0;
			}
			else{
				currentSum = cumarr[j] - cumarr[i-1];
			}
			
			if (maxSum < currentSum){
				maxSum = currentSum;
			}
		}
	}
	
	return maxSum;
}