/**
	二叉查找树的范围查找操作
*/
public Iterable<Key> keys(){
	return keys(min(), max());
}

public Iterable<Key> keys(Key lo, Key hi){
	Queue<Key> queue = new Queue<Key>();
	keys(root, queue, lo, hi);
	return queue;
}

private void keys(Node x, Queue<Key> queue, Key lo, Key hi){
	if (x == null){
		return ;
	}
	int cmplo = lo.compareTo(x.key);
	int cmphi = hi.compareTo(x.key);
	if (cmplo < 0){
		keys(x.left, queue, lo, hi);
	}
	if (cmplo <= 0 && cmphi >= 0){
		queue.enqueue(x.key);
	}
	if (cmphi > 0){
		keys(x.right, queue, lo, hi);
	}
}