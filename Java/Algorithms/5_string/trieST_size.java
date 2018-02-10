/**
	延迟递归方法 -- 单词查找树的size()
*/
public int size(){
	return size(root);
}

private int size(Node x){
	if (x == null){
		return 0;
	}
	
	int cnt = 0;	// 从低向上，没有问题
	if (x.val != null){
		cnt++;
	}
	for (char c = 0; c < R; c++){
		cnt += size(next[c]);
	}
	
	return cnt;
}