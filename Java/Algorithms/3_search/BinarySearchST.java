/**
	二分查找
	
	有序数组
*/
public class BinarySearchST<Key extends Comparable<Key>, Value>{
	private Key[] keys;
	private Values[] vals;
	private int N;
	
	public BinarySearchST(int capacity){
		keys = (Key[]) new Comparable[capacity];
		vals = (Value[]) new Object[capacity];
	}
	
	public int size(){
		return N;
	}
	
	public Value get(Key key){
		if (isEmpty()){
			return null;
		}
		int i = rank(key);
		if (i < N && keys[i].compareTo(key) == 0){
			return vals[i];
		}
		else{
			return null;
		}
	}
	
	public int rank(Key key){
		// TODO
		int lo = 0;
		int hi = N - 1;
		while (lo <= hi){
			int mid = (hi - lo) / 2 + lo;
			int cmp = key.compareTo(keys[mid]);
			if (cmp < 0){
				hi = mid - 1;
			}
			else if (cmp > 0){
				lo = mid + 1;
			}
			else{
				return mid;
			}
		}
		return lo;
	}
	
	public void put(Key key, Value val){
		int i = rank(key);
		if (i < N && keys[i].compareTo(key) == 0){
			vals[i] = val;
			return ;
		}
		for (int j = N; j > i; j--){
			keys[j] = keys[j-1];
			vals[j] = vals[j-1];
		}
		keys[i] = key;
		vals[i] = val;
		N++;
	}
	
	public void delete(Key key){
		// TODO
		int i = rank(key);
		if (i < N && key.compareTo(keys[i]) == 0){
			for (int j = i; j+1 < N; j++){
				keys[j] = keys[j+1];
				vals[j] = vals[j+1];
			}
			N--;
		}
	}
	
	public Key min(){
		return keys[0];
	}
	
	public Key max(){
		return keys[N-1];
	}
	
	public Key select(int k){
		return keys[k];
	}
	
	public Key ceiling(Key key){
		int i = rank(key);
		return keys[i];
	}
	
	public Key floor(Key key){
		// TODO
		int i = rank(key);
		if (key.compareTo(keys[i]) == 0){
			return keys[i];
		}
		else{
			return keys[i-1];
		}
	}
	
	public Iterable<Key> keys(Key lo, Key hi){
		Queue<Key> q = new Queue<Key>();
		for (int i = rank(lo); i < rank(hi); i++){
			q.enqueue(keys[i]);
		}
		if (contains(hi)){
			q.enqueue(keys[rank(hi)]);
		}
		return q;
	}
}