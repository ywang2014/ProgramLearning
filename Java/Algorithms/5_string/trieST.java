/**
	基于单词查找树的符号表
*/
public class TrieST<Value>{
	private static int R = 256;
	private Node root;
	
	private static class Node{
		private Object val;
		private Node[] next = new Node[R];
	}
	
	public Value get(String key){
		Node x = get(root, key, 0);
		if (x == null){
			return null;
		}
		return (Value) x.val;
	}
	
	private Node get(Node x, String key, int d){
		if (x == null){
			return null;
		}
		if (d == key.length()){
			return x;
		}
		
		char c = key.cahrAt(d);
		return get(x.next[c], key, d+1);
	}
	
	public void put(String key, Value val){
		root = put(root, key, val, 0);
	}
	
	private Node put(Node x, String key, Value val, int d){
		if (x == null){
			x = new Node();	// 创建一个新节点，继续扩展
		}
		if (d == key.length()){
			x.val = val;
			return x;
		}
		
		char c = key.charAt(d);
		x.next[c] = put(x.next[c], key, val, d+1);
		return x;
	}
	
	// 收集一棵单词查找树中的所有键
	public Iterable<String> keys(){
		return keyWithPrefix("");
	}
	
	public Iterable<String> keysWithPrefix(string pre){
		Queue<String> q = new Queue<String>();
		collect(get(root, pre, 0), pre, q);
		return q;
	}
	
	private void collect(Node x, String pre, Queue<String> q){
		if (x == null){
			return ;
		}
		
		if (x.val != null){
			q.enqueue(pre);
		}
		for (char c = 0; c < R; c++){
			collect(x.next[c], pre+c, q);
		}
	}
	
	// 单词查找树中的通配符匹配
	public Iterable<String> keysThatMatch(String pat){
		Queue<String> q = new Queue<String>();
		collect(root, "", pat, q);
		return q;
	}
	
	public void collect(Node x, String pre, String pat, Queue<String> q){
		int d = pre.length();
		if (x == null){
			return ;
		}
		if (d == pat.length() && x.val != null){
			q.enqueue(pre);
		}
		if (d == pat.length()){
			return ;
		}
		
		char next = pat.charAt(d);
		for (char c = 0; c < R; c++){
			if (next == '.' || next == c){
				// pre越来越长了
				collect(x.next[c], pre + c, pat, q);
			}
		}
	}
	
	// 对给定字符串的最长前缀进行匹配
	public String longestPrefixOf(String s){
		int length = search(root, s, 0, 0);
		return s.substring(0, length);
	}
	
	private int search(Node x, String s, int d, int length){
		if (x == null){
			return length;
		}
		if (x.val != null){
			length = d;
		}
		if (d == s.length()){
			return length;
		}
		
		char c = s.charAt(d);	// c为什么没有转化为索引
		return search(x.next[c], s, d+1, length);
	}
	
	// 删除节点操作
	public void delete(String key){
		root = delete(root, key, 0);
	}
	
	private Node delete(Node x, String key, int d){
		if (x == null){
			return null;
		}
		
		if (d == key.length()){
			x.val = null;
		}
		else{
			char c = key.charAt(d);
			x.next[c] = delete(x.next[c], key, d+1);
		}
		
		if (x.val != null){
			return x;
		}
		for (char c = 0; c < R; c++){
			if (x.next[c] != null){
				return x;
			}
		}
		return null;
	}
}