/**
	顺序查找表
	
	链表实现
*/
public class SequentialSearchST<Key, Value>{
	private Node first;
	private class Node{
		Key k;
		Value v;
		Node next;
		
		public Node(Key key, Value value, Node next){
			this.k = key;
			this.v = value;
			this.next = next;
		}
	}
	
	public Value get(Key key){
		for (Node x = first; x != null; x = x.next){
			if (key.equals(x.k)){
				return x.v;
			}
		}
		return null;
	}
	
	public void put(Key key, Value value){
		for (Node x = first; x != null; x = x.next){
			if (key.equals(x.k)){
				x.v = value;
				return ;
			}
		}
		Node newNode = new Node(key, value, first);
		first = newNode;
	}
	
	public int size(){
		int count = 0;
		for (Node x = first; x != null; x = x.next){
			count++;
		}
		return count;
	}
	
	public Iterator<Key> keys(){
		// TODO
	}
	
	public void delete(Key key){
		for (Node x = first; x != null; x = x.next){
			if (key.equals(x.k)){
				Node del = x.next;
				x.next = del.next;
				x.v = del.v;
				x.k = del.k;
				del = null;
				
			}
		}
	}
}