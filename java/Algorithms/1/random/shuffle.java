/**
	随机将double数组中的元素排序
*/
public static void shuffle(double[] a){
	int N = a.length;
	for (int i = 0; i < N; i++){
		int r = i + StdRandom.uniform(N - i);
		double temp = a[i];
		a[i] = a[r];
		a[r] = temp;
	}
}