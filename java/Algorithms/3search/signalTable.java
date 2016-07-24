/**
	符号表的实现
	
	方便实现删除操作和判断一个键是否在符号表中，不允许有null值。
	不予许键为null
*/
public class ST<Key, Value>{
	public Value get(Key k);
	public void put(Key k, Value v);
	
	public void delete(Key k){
		put(k, null);
	}
	
	public boolean contains(Key k){
		return get(k) != null;
	}
	
	public boolean isEmpty(){
		return size() == 0
	}
	
	public size_t size();
}