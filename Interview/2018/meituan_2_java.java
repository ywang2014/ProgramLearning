/**
	美团二面的编程题目
	
	一颗有序的二叉查找树，给一个数字V，找出大于V的最小节点。
*/
class TreeNode{
	private int v;
	private TreeNode left;
	private TreeNode right;
	
	public int getValue(){
		return this.value;
	}
	
	public TreeNode getLeft(){
		return this.left;
	}
	
	public TreeNode getRight(){
		return this.right;
	}
	
	public boolean isLeft(TreeNode node){
		return this == node.getLeft();
	}
}

// version 1
TreeNode findSuccessor(TreeNode root, int v){
    if (root == null){
        return null;
    }
    TreeNode q = root;
    TreeNode p = null;	// parent node
    while (q != null){
        if (q.getValue() < v){
            if (q.getRight() == null){
				return getRightNodeSuccessor(root, q);
            } else {
                p = q;
                q = q.getRight();
            }
        } else if (q.getValue() > v){
            if (q.getLeft() == null){
                return q;
            } else {
                p = q;
                q = q.getLeft();
            }
        } else {
			if (p == null){ // root node
				return getNodeSuccesor(root);
			}
			
			if (q.isLeft(p)){ // 如果是左孩子
				if (q.getRight() == null){	// 没有右孩子
					return q;
				} else {
					return getMinLeftSuccesor(q.getRight());
				}
			} else {	// 如果是右孩子
				return getRightNodeSuccessor(root, p);
			}
        }
    } // while end
}

// 跟节点后继
public TreeNode getRootNodeSuccessor(TreeNode root){
	if (root.getRight() == null){
		return null;
	}
	return getMinLeftSuccesor(root.getRight());
}

public TreeNode getMinLeftSuccesor(TreeNode node){
	TreeNode q = node;
	while (q.getLeft() != null){
		q = q.getLeft();
	}
	return q;
}

// 遍历右孩子的时候，后继节点，不会变化的，遍历左孩子的时候，后继节点会更新一次。
public TreeNode getRightNodeSuccessor(TreeNode root, TreeNode node){
	TreeNode q = root;
	TreeNode successor = null;
	while (q != null){
		if (q.getValue() > node.getValue()){
			successor = q;
			q = q.getLeft();
		} else if (q.getValue < node.getValue()){
			p = p.getRight();
		} else {	// must be here, then return
			return successor;
		}
	}
}

public TreeNode getLeftSuccessor(TreeNode root, TreeNode node){
	TreeNode q = root;
	TreeNode p = null;
	while (q != node){
		if (q.getValue() < node.getValue()){
			p = q;
			q = q.getRight();
		} else if (q.getValue() > node.getValue()){
			p = q;
			q = q.getLeft();
		} else {	// must be here, then return
			if (q.getRight() == null){
				return p;
			} else {
				return getMinLeftSuccesor(q.getRight());
			}
		}
	}
}

//////////////////////////////////////////////////////////////////
// version 2
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