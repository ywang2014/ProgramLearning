/**
	确定一组矩形中，是否存在重叠的矩形
*/
#include "mergeSort.h"

void merge(Rectangle *arr, int low, int mid, int high){
	if (low < 0 || mid < 0 || high < 1 || mid < low || high < mid){
		return;	// invalid parameters
	}

	int l_len = mid - low;
	Rectangle *left = new Rectangle[l_len];
	for (int i = 0; i < l_len; i++){
		left[i] = arr[low + i];
	}
	int r_len = high - mid;
	Rectangle *right = new Rectangle[r_len];
	for (int j = 0; j < r_len; j++){
		right[j] = arr[mid + j];
	}

	int i = 0;
	int j = 0;
	/*int k = low;
	while (i < l_len || j < r_len){*/
	for (int k = low; k < high;){
		while (i < l_len && (j >= r_len || left[i].l_t.x <= right[j].l_t.x)){
			arr[k++] = left[i++];
		}
		while (j < r_len && (i >= l_len || left[i].l_t.x > right[j].l_t.x)){
			arr[k++] = right[j++];
		}
	}

	delete[] left;
	delete[] right;
}

void mergeSort_3(Rectangle *arr, int low, int high){
	if (low < (high - 1)){
		int mid = low + (high - low) / 2;
		mergeSort_3(arr, low, mid);
		mergeSort_3(arr, mid, high);
		merge(arr, low, mid, high);
	}
}

void mergeSort(Rectangle *arr, int n){
	mergeSort_3(arr, 0, n);
}


bool isOverlap(Rectangle l, Rectangle r){
	if (l.l_t.x > r.r_b.x || l.r_b.x < r.l_t.x || l.l_t.y < r.r_b.y || l.r_b.y > r.l_t.y){
		return false;
	}
	return true;
}

bool rectOverlap(Rectangle *arr, int n){
	// 以x轴为坐标排序
	mergeSort(arr, n);

	bool res = false;
	for (int i = 1; i < n; i++){
		if (arr[i - 1].r_b.x > arr[i].l_t.x){
			res = isOverlap(arr[i-1], arr[i]);
			if (res){
				break;
			}
		}
		// 漏洞：可能有的矩形非常宽，r_b.x非常大，但是很矮，不与相邻的矩形重叠，可能与后面的矩形有重叠
		
		// x = max(x, arr[i].r_b.x); 可以有效的检测x方向的重叠区域，但是y方向不能解决。
		// 漏洞：很可能检测的两个矩形没有重叠，因为重叠还关系y轴，但是其他相邻的矩形可能有重叠
		
		// O(nlogn)?  O(n^2)
	}
	
	return res;
}
