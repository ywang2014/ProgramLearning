/**
	有序符号表
*/
public class ST<Key extends Comparable<key>, Value>{
	public ST();
	public void put(Key k, Value v);
	public Value get(Key k);
	public void delete(Key k);
	public boolean contains(Key k);
	public boolean isEmpty()
	public int size();
	public Key min();
	public Key max();
	public Key floor(Key k);	// 小于等于key的最大键
	public Key ceiling(key k);	// 大于等于key的最小键
	public int rank(Key k);		// 小于key的键的数目
	public Key select(int k);	// 排名为k的键
	public void deleteMin(){
		delete(min());
	}
	
	public void deleteMax(){
		delete(max());
	}
	
	public int size(Key lo, Key hi){
		if (hi.compareTo(lo) < 0){
			return 0;
		}
		else if (contains(hi)){
			return rank(hi) - rank(lo) + 1;
		}
		else{
			return rank(hi) - rank(lo);
		}
	}
	public Iterable<Key> keys(Key lo, Key hi);
	// 表中所有键的集合，已排序
	public Iterable<Key> keys(){
		return keys(min(), max());
	}	
}