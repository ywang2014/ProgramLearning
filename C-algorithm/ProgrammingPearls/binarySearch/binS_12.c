/**
	二分查找
	
	改进的版本
	l, i表示l, u i总是2的整数幂
*/

int binarySearch(int *arr, int n, int t){
	int i = 512;	// 假设n为1000，i是不大于n的最大2的幂
	int l = -1;
	
	if (arr[511] < t){
		l = 1000 - 512;		// n默认1000
	}
	while (i != 1){
		int nexti = i / 2;
		if (arr[l + nexti] < t){
			l = l + nexti;
		}
		i = nexti;
	}
	// assert i==1 && arr[l]<t && arr[l+i]>=t
	int p = l+1;
	if (p > 1000 || arr[p] != t){
		p = -1;
	}
	
	return p;
}


/*************************************************************/
int binarySearch(int *arr, int n, int t){
	int i = 512;	// 假设n为1000，i是不大于n的最大2的幂
	int l = -1;
	
	if (arr[511] < t){
		l = 1000 - 512;		// n默认1000
	}
	while (i != 1){
		i = i / 2;
		if (arr[l + i] < t){
			l = l + i;
		}
	}
	// assert i==1 && arr[l]<t && arr[l+i]>=t
	int p = l+1;
	if (p > 1000 || arr[p] != t){
		p = -1;
	}
	
	return p;
}

/******************************************************/
int binarySearch(int *arr, int n, int t){
	int l = -1;
	
	if (arr[511] < t){
		l = 1000 - 512;		// n默认1000
	}
	
	// 展开循环
	if (arr[l+256] < t){
		l += 256;
	}
	if (arr[l+128] < t){
		l += 128;
	}
	if (arr[l+64] < t){
		l += 64;
	}
	if (arr[l+32] < t){
		l += 32;
	}
	if (arr[l+16] < t){
		l += 16;
	}
	if (arr[l+8] < t){
		l += 8;
	}
	if (arr[l+4] < t){
		l += 4;
	}
	if (arr[l+2] < t){
		l += 2;
	}
	if (arr[l+1] < t){
		l += 1;
	}
	
	// assert i==1 && arr[l]<t && arr[l+i]>=t
	int p = l+1;
	if (p > 1000 || arr[p] != t){
		p = -1;
	}
	
	return p;
}
