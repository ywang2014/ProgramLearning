/**
	红黑树的插入算法
*/
public class RedBlackBST<Key extends Comparable<Key>, Value>{
	private Node root;
	
	private static boolean RED = true;
	private static boolean BLACK = false;
	
	private class Node{
		Key key;
		Value val;
		Node left;
		Node right;
		boolean color;
		int n;
	}
	
	private boolean isRed(Node h){
		if (x == null){
			return false;
		}
		return h.color;
	}
	
	private Node rotateLeft(Node h);
	
	private Node rotateRight(Node h);
	
	private void flipColors(Node h){
		h.color = RED;
		h.left.color = BLACK;
		h.right.color = BLACK;
	}
	
	private int size(){
		return size(root);
	}
	
	private int size(Node h){
		if (h == null){
			return 0;
		}
		return h.n;
	}
	
	public void put(Key k, Value v){
		root = put(root, k, v);
		root.color = BLACK;
	}
	
	private Node put(Node h, Key key, Value val){
		if (h == null){
			return new Node(key, val, 1, RED);
		}
		
		int cmp = key.compareTo(h.key);
		if (cmp < 0){
			h.left = put(h.left, key, val);
		}
		else if (cmp > 0){
			h.right = put(h.right, key, val);
		}
		else{
			h.val = val;
		}
		
		if (isRed(h.right) && !isRed(h.left)){
			h = rotateLeft(h);
		}
		if (isRed(h.left) && isRed(h.left.left)){
			h = h.rotateRight(h);
		}
		if (isRed(h.left) && isRed(h.right)){
			flipColors(h);
		}
		
		h.n = size(h.left) + size(h.right) + 1;
		
		return h;
	}
}