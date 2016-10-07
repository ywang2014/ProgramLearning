/**
	二叉查找树中API实现
	
	delete operation
*/

public void deleteMin(){
	root = deleteMin(root);
}

private Node deleteMin(Node x){
	if (x.left == nullptr){
		return x.right;
	}
	x.left = deleteMin(x.left);
	x.N = size(x.left) + size(x.right) + 1;
	return x;
}

public void delete(Key key){
	root = delete(root, key);
}

private Node delete(Node x, Key key){
	if (x == nullptr){
		return nullptr;
	}
	
	int cmp = key.compareTo(x.key);
	if (cmp < 0){
		x.left = delete(x.left, key);
	}
	else if (cmp > 0){
		x.right = delete(x.right, key);
	}
	else{
		if (x.right == nullptr){
			return x.left;
		}
		if (x.left == nullptr){
			return x.right;
		}
		Node t = x;
		x = min(t.right);
		x.right = deleteMin(t.right);
		x.left = t.left;
	}
	x.N = size(x.left) + size(x.right) + 1;
	return x;
}