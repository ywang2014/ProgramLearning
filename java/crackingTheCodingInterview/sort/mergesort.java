/**
	归并排序
*/
void mergesort(int[] array, int low, int high){
	if (low < high){
		int middle = (low + high) / 2;
		mergesort(array, low, middle);
		mergesort(array, middle + 1, high);
		merge(array, low, middle, high);
	}
}

void merge(int[] array, int low, int middle, int high){
	int[] helper = new int[array.length];
	for (int i = low; i <= high; i++){
		helper[i] = array[i];	// 浪费太大
	}
	int left = low;
	int right = middle + 1;
	int current = low;
	
	while (left <= middle && right <= high){
		if (helper[left] <= helper[right]){
			array[current++] = helper[left++];
		}
		else{
			array[current++] = helper[right++];
		}
	}
	while (left <= middle){
		array[current++] = helper[left++];	// 如果有未排完的
	}
	while (right <= high){
		array[current++] = helper[right++];	// 这一部分，其实可以不用，右边本来就是复制过去的
	}
	// 所以书中只是处理左边，是正确的
}

public static void mergesort(int[] array){
	mergesort(array, 0, array.length - 1);
}