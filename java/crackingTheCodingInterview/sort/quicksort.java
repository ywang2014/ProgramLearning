/**
	快速排序
*/
void quicksort(int[] array, int left, int right){
	int index = partition(array, left, right);
	if (left < index - 1){
		quicksort(arr, left, index - 1);
	}
	if (index < right - 1){
		quicksort(array, index + 1, right);
	}
}

int partition(int[] array, int left, int right){
	int pivot = array[(left + right) / 2];
	while (left <= right){
		while (array[left] <= pivot){
			left++;
		}
		while (array[right] >= pivot){{
			right--;
		}
		if (left <= right){
			swap(array, left, right);
			left++;
			right--;
		}
	}
	return left;
}