/**
	二叉查找树中API实现
*/

public Key min(){
	return min(root).key;
}

private Node min(Node x){
	if (x.left == nullptr){
		return x;
	}
	return min(x.left);
}

public Key max(){
	return max(root).key;
}

private Node max(Node x){
	if (x.right == nullptr){
		return x;
	}
	return max(x.right);
}

public Key floor(Key key){
	Node x = floor(root, key);
	if (x == nullptr){
		return nullptr;
	}
	return x.key;
}

private Node floor(Node x, Key key){
	if (x == nullptr){
		return nullptr;
	}
	int cmp = key.compareTo(x.key);
	if (cmp == 0){
		return x;
	}
	else if (cmp < 0){
		return floor(x.left, key);
	}
	Node t = floor(x.right, key);
	if (t != nullptr){
		return t;
	}
	else{
		return x;
	}
}

public Key ceiling(Key key){
	Node res = ceiling(root, key);
	return res == nullptr ? nullptr: res.key;
}

private Node ceiling(Node x, Key key){
	// TODO
	if (x == nullptr){
		return nullptr;
	}
	
	int cmp = key.compareTo(x.key);
	if (cmp == 0){
		return x;
	}
	if (cmp > 0){
		return ceiling(x.right, key);
	}
	Node tmp = ceiling(x.left, key);
	if (tmp == nullptr){
		return x;
	}
	return tmp;
}

public Key select(int k){
	return select(root, k).key;
}

// 返回排名为k的节点
private Node select(Node x, int k){
	if (x == nullptr){
		return nullptr;
	}
	
	int t = size(x.left);
	if (t > k){
		return select(x.left, k);
	}
	else if (t < k){
		return select(x.right, k-t-1);
	}
	return x;
}

public int rank(Key k){
	return rank(root, k);
}

private int rank(Node x, Key key){
	if (x == nullptr){
		return 0;
	}
	
	int cmp = key.compareTo(x.key);
	if (cmp < 0){
		return rank(x.left, key);
	} 
	else if (cmp > 0){
		return 1 + size(x.left) + rank(x.right, key);
	}
	return size(x.left);
}