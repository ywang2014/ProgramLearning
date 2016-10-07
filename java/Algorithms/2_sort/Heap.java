/**
	Heap
*/
public class Heap{
	// 上浮
	private void swim(int k){
		while (k > 1 && less(k / 2, k)){
			exch(k / 2, k);
			k = k / 2;
		}
	}
	
	// 下沉
	private void sink(int k){
		while (2 * k <= N){
			int i = 2 * k;
			if (i < N && less(i , i + 1)){
				i++;
			}
			if (!less(k, i)){
				break;
			}
			exch(k, i);
			k = i;
		}
	}
}