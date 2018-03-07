// 从二叉查找树中，找到大于v的最小节点。
TreeNode findSuccessor(TreeNode root, int v){
    if (root == null){
        return null;
    }
    TreeNode q = root;
    TreeNode successor = null;
    while (q != null){
        if (q.getValue() < v){
            // 分支的右孩子，不改变其后继节点
            q = q.getRight();
        } else if (q.getValue() > v){
            successor = q;	// 分支的左孩子，一定是以其父亲作为后继节点
            q = q.getLeft();
        } else {
			if (q.getRight()){ // 存在右孩子
				successor = getMinLeftSuccesor(q.getRight());
			}
			break;
        }
    } // while end
	return successor;
}

public TreeNode getMinLeftSuccesor(TreeNode node){
	TreeNode q = node;
	while (q.getLeft() != null){
		q = q.getLeft();
	}
	return q;
}