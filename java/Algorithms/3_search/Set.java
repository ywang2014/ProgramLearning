/**
	Set 实现
*/
public class Set<Key>{
	private int n;
	private int cap;
	private[] Key keys;
	
	public Set(){
		this.Set(16);
	}
	
	public Set(int cap){
		this.cap = cap;
		this.n = 0;
		keys = new Key[cap];
	}
	
	public void add(Key k){
		if (! contains(k) && n < cap){
			keys[n++] = k;
		}
	}
	
	public void delete(Key k){
		for (int i = 0; i < n; i++){
			if (k.equals(keys[i])){
				for (int j = i; j < n - 1; j++){
					keys[j] = keys[j+1];
				}
				n--;
				break;
			}
		}
	}
	
	public boolean contains(Key k){
		for (int i = 0; i < n; i++){
			if (k.equals(keys[i])){
				return true;
			}
		}
		return false;
	}
	
	public boolean isEmpty(){
		return n == 0;
	}
	
	public int size(){
		return n;
	}
	
	public String toString(){
		// TODO
	}
}