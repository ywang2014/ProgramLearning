/**
	插入排序
*/
void swap(int *a, int *b){
	int old_a = *a;
	*a = *b;
	*b = old_a;
}

void insert(int *arr, int n){
	if (arr == NULL || n < 1){
		return ;	// invalid
	}
	
	for (int i = 1; i < n; i++){
		for (int j = i; j > 0 && arr[j] < arr[j-1]; j--){
			swap(&arr[j], &arr[j-1]);
		}
	}
}

/********************** 版本二 **************/
void insert(int *arr, int n){
	assert(arr != NULL && n > 0);
	
	for (int i = 1; i < n; i++){
		int temp = arr[i];
		for (int j = i; j > 0 && temp < arr[j-1]; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}