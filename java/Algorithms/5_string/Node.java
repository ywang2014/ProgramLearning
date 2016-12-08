/**
	单词查找树的节点实现
	
	霍夫曼单词查找树
*/
private static class Node implements Comparable<Node>{
	private char ch;
	private int freq;
	private final Node left;
	private final Node right;
	
	Node(char ch, int freq, Node left, Node right){
		this.ch = ch;
		this.freq = freq;
		this.left = left;
		this.right = right;
	}
	
	public boolean isLeaf(){
		return left == null && right == null;
	}
	
	public int compareTo(Node that){
		return this.freq - that.freq;
	}
}