/**
	基于线性探测的符号表
*/
public class LinearProbingHashST<Key, Value>{
	private int N;
	private int M;
	private Key[] keys;
	private Value[] vals;
	
	public LinearProbingHashST(){
		M = 16;
		keys = (Key[]) new Object[M];
		vals = (Value[]) new Object[M];
	}
	
	private int hash(Key k){
		return (k.hashCode() & 0x7fffffff) % M;
	}
	
	private void resize(){
		// TODO
	}
	
	public void put(Key k, Value v){
		if (N >= M / 2){
			resize(2 * M);
		}
		int i;
		for (i = hash(k); keys[i] != null; i = (i + 1) % M){
			if (keys[i].equals(k)){
				vals[i] = v;	// 更新value
				return ;
			}
		}
		// 插入新的键值对
		keys[i] = k;
		vals[i] = v;
		N++;
	}
	
	public Value get(Key k){
		for (int i = hash(k); keys[i] != null; i = (i + 1) % M){
			if (k.equals(keys[i])){
				return vals[i];
			}
		}
		return null;
	}
	
	public Key[] keys(){
		// TODO
	}
	
	// 删除操作：需要将被删除元素的右侧簇中所有键值重新插入，简单的置为null是错误的
	public void delete(Key k){
		if (!contains(k)){
			return ;
		}
		int i = hash(k);
		while (!k.equals(keys[i])){
			i = (i + 1) % M;
		}
		keys[i] = null;
		vals[i] = null;
		i = (i + 1) % M;
		while (keys[i] != null){
			Key keyToRedo = keys[i];
			Value valToRedo = vals[i];
			keys[i] = null;
			vals[i] = null;
			N--;
			put(keyToRedo, valToRedo);
			i = (i + 1) % M;
		}
		N--;
		if (N > 0 && N == M / 8){
			resize(M / 2);
		}
	}
}

private void resize(int size){
	if (M == size){
		return ;
	}
	Key[] newKeys = new Key[size];
	Value[] newVals = new Value[size];
	System.arraycopy(keys, 0, newKeys, 0, M);
	System.arraycopy(vals, 0, newVals, 0, M);
	M = size;
	keys = newKeys;
	vals = newVals;
}

public void delete(Key k){
	int i = hash(k);
	boolean in = false
	for (; keys[i] != null; i = (i + 1) % M){
		if (k.equals(keys[i])){
			in = true;
			keys[i] = null;
			vals[i] = null;
		}
		else if (in){
			Key keyToRedo = keys[i];
			Value valToRedo = vals[i];
			keys[i] = null;
			vals[i] = null;
			N--;
			put(keyToRedo, valToRedo);
			// 重构不存在问题：键值对新插入时，不可能放在更右边的地方！
		}
	}
	if (in){
		N--;
		if (N > 0 && N == M / 8){
			resize(M / 2);
		}
	}
}