/**
	B-树集合的实现
*/
public class BTreeSET<Key extends Comparable<Key>>{
	private Page root = new Page(true);
	
	public BTreeSET(Key sentinel){
		put(sentinel);
	}
	
	public boolean contains(Key key){
		return contains(root, key);
	}
	
	private boolean contains(Page h, Key key){
		if (h.isExternal()){
			return h.contains(key);
		}
		return contains(h.next(key), key);
	}
	
	public void add(Key key){
		put(root, key);
		if (root.isFull()){
			Page lefthalf = root;
			Page righthalf = root.split();
			root = new Page(false);
			root.put(lefthalf);
			root.put(righthalf);
		}
	}
	
	public void add(Page h, Key key){
		if (h.isExternal()){
			h.put(key);
			return ;
		}
		Page next = h.next(key);
		put(next, key);
		if (next.isFull()){
			h.put(next.split());
		}
		next.close();
	}
}
