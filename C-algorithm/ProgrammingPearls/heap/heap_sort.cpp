/**
	堆排序的实现
*/
void heap_sort(int v[], int n){
	// assert arguments
	
	for (int i = n / 2; i >= 0; i--){
		int child = 2 * i + 1;	// 左孩子
		for (int j = i; child < n; j = child, child = 2*j+1){
			if ( ((child + 1) < n) && v[child+1] > v[child] ){
				child++;
			}
			if (v[j] < v[child]){	// 保证排序是增长序的，所以使用大根堆
				swap(v[j], v[child]);
			}
			else{
				break;
			}
		}
	}
	
	for (int i = n - 1; i >= 2; i--){
		swap(v[i], v[0]);	// 排序，最大的数，放在了最后
		int child;
		for (int j = 0; (child = 2 * j + 1) < i; j = child){	// i = size;
			if (child + 1 < i && v[child+1] > v[child]){
				child++;
			}
			if (v[j] < v[child]){
				swap(v[j], v[child]);
			}
			else{
				break;
			}
		}
	}
}