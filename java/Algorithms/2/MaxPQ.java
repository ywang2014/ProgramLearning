/**
	基于堆的优先队列
*/
public class MaxPQ<Key extends Comparable<Key> >{
	private Key[] pq;
	private int N = 0;
	
	public MaxPQ(int maxN){
		pq = (Key[]) new Comparable[maxN + 1];
	}
	
	public boolean isEmpty(){
		return N == 0;
	}
	
	public int size(){
		return N;
	}
	
	public void insert(Key v){
		pq[++N] = v;
		swim(N);
	}
	
	public Key delMax(){
		Key max = pq[1];
		exch(1, N--);
		pq[N + 1] = null;
		sink(1);
		return max;
	}
	
	// helper
	private boolean less(int i, int j){
		return pq[i].compare(pq[j]);
	}
	
	private void exch(int i, int j){
		Key oldI = pq[i];
		pq[i] = pq[j];
		pq[j] = oldI;
	}
	
	private void swim(int k){
		while (k > 1 && less(k / 2, k)){
			exch(k / 2, k);
			k = k / 2;
		}
	}
	
	private void sink(int k){
		while (2 * k <= N){
			int index = 2 * k;
			if (index < N && less(index, index + 1)){
				index++;
			}
			if (less(k, index)){
				exch(k, index);
				k = index;
			}
			else{
				break;
			}
		}
	}
}