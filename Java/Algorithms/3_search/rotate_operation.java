/**
	红黑树的旋转操作
*/

// 左旋
Node rotateLeft(Node h){
	Node x = h.right;
	h.right = x.left;
	x.left = h;
	
	x.n = h.n;
	h.n = 1 + size(h.left) + size(h.right);
	x.color = h.color;
	h.color = RED;
	
	return x;
}

// 右旋
Node rotateRight(Node h){
	Node x = h.left;
	h.left = x.right;
	x.right = h;
	
	x.n = h.n;
	h.n = 1 + size(h.left) + size(h.right);
	x.color = h.color;
	h.color = RED;
	
	return x;
}

// 颜色调整
void flipColors(Node h){
	h.color = RED;
	h.left.color = BLACK;
	h.left.color = BLACK;
}