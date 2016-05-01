/**
	随机序列生成器
	
	m=0，程序就会死掉
*/

void randArray(int *arr, int n, int m){
	int select = m;
	int remaining = n;
	
	for (int i = 0; i < n; i++){
		if ((rand() % remaining) < select){
			arr[index++] = i;	// 选择i
			select--;
		}
		remaining--;
	}
}