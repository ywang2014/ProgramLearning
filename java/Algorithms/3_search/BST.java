/**
	基于二叉查找树的符号表
*/
public class BST<Key extends Comparable<Key>, Value>{
	private Node root;
	
	private class Node{
		private Key key;
		private Value val;
		private Node left;
		private Node right;
		private int N;
		
		public Node(Key k, Value v, int N){
			key = k;
			val = v;
			this.N = N;
		}
	}
	
	public int size(){
		return size(root);
	}
	
	private int size(Node x){
		if (x == null){
			return 0;
		}
		else{
			return x.N;
		}
	}
	
	public Value get(Key key){
		return get(root, key);
	}
	
	private Value get(Node x, Key key){
		if (x == null){
			return null;
		}
		
		int cmp = key.compareTo(x. key);
		if (cmp < 0){
			get(x.left, key);
		}
		else if (cmp > 0){
			get(x.right, key);
		}
		else{
			return x.val;
		}
	}
	
	public void put(Key key, Value, val){
		root = put(root, key, val);
	}
	
	private Node put(Node x, Key key, Value val){
		if (x == null){
			return new Node(key, val, 1);
		}
		int cmp = key.compareTo(x.key);
		if (cmp < 0){
			x.left = put(x.left, key, val);
		}
		else if (cmp > 0){
			x.right = put(x.right, key, val);
		}
		else{
			x.val = val;
		}
		
		// 使用x.N++也可以的
		x.N = size(x.left) + size(x.right) + 1;
		return x;
	}
	
	// max() min() floor() ceiling()
	// select() rank()
	// delete() deleteMin() deleteMax()
	// keys
}