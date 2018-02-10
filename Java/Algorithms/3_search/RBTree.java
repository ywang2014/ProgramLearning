/**
	红黑树的节点表示
	
	红黑树：
		红色链接都是左链接
		没有任一节点同时和两条红色链接相连
		红黑树是完美黑色平衡的
		
		红黑树与2-3树一一对应，3-节点对应于：一条红色左链接+两个2-节点。
		
	颜色理解：红色左链接，指向的节点，定义为红色节点
		1.红色节点只可能是左孩子节点
		2.红节点的父节点，子节点都不可能是红色节点
		3.所有路径上，黑色节点数都是一样的
		
	----------------------------------------------------------------------
	Weiss数据结构与算法分析中，红黑树定义：
		1.每一个节点是红色或者黑色
		2.根节点是黑色
		3.如果一个节点是红色，其子节点必须是黑色的
		4.从根节点到NULL节点的所有路径上，黑色节点数都是一样的
		
*/

private static final boolean RED = true;
private static final boolean BLACK = false;

private class Node{
	Key key;
	Value val;
	Node left;
	Node right;
	int n;
	boolean color;
	
	Node(Key k, Value v, int n, boolean color){
		key = k;
		val = v;
		this.n = n;
		this.color = color;
	}
}

private boolean isRed(Node x){
	if (x == null){
		return false;
	}
	return x.color == RED;
}

