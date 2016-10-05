/**
	基于拉链法的散列表
*/
public class SeparateChainingHashST<Key, Value>{
	private int N;	// 键值对总数
	private int M;	// 散列表大小
	private SequentialSearchST<Key, Value>[] st;	// 存放链表对象的数组
	
	public SeparateChainingHashST(){
		this(997);
	}
	
	public SeparateChainingHashST(int m){
		this.M = m;
		st = (SequentialSearchST<Key, Value>[]) new SequentialSearchST[m];
		for (int i = 0; i < m; i++){
			st[i] = new SequentialSearchST();
		}
	}
	
	private int hash(Key k){
		return (key.hashCode() & 0x7fffffff) % M;
	}
	
	public Value get(Key k){
		return (Value) st[hash(k)].get(k);
	}
	
	public void put(Key k, Value v){
		st[hash(k)].put(k, v);
	}
	
	public Iterable<Key> keys(){
		// TODO
	}
}