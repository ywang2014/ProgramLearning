/**
	键索引计数法
*/
public static void keyCountSort(char[] a){
	int N = a.length;  
	String[] aux = new String[N];
	int[] count = new int[R+1];
	
	// 统计频率
	for (int i = 0; i < N; i++){
		count[a[i].key()+1]++;
	}
	
	for (int r = 0; r < R; r++){
		count[r+1] += count[r];
	}
	
	// 排序
	for (int i = 0; i < N; i++){
		aux[count[a[i].key()]++] = a[i];
	}
	
	// 回写
	for (int i = 0; i < N; i++){
		a[i] = aux[i];
	}
}