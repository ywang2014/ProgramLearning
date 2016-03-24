/**
	判断一棵二叉树，是否是平衡二叉树。
	如果某二叉树中，任意根节点的左右子树的深度，相差不超过1，那么它就是一颗平衡二叉树。
	
	例如：如下就是一颗平衡二叉树
	         1
	     2          3
	  4     5          6
	      7
*/

// 简单低效率的实现方法
bool isBalanced(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	
	int left = treeDepth(root->left);
	int right = treeDepth(root->right);
	
	int diff = left - right;
	if (diff < -1 || diff > 1)
	{
		return false;
	}
	
	return isBalanced(root->left) && isBalanced(root->right);
}


// 后序遍历判断，一次遍历即可
bool isBalanced(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	
	int depth = 0;
	
	return isBalanced(root, &depth);
}

bool isBalanced(BinaryTreeNode* root, int* depth)
{
	if (root == NULL)
	{
		return true
	}
	
	if (depth == NULL)
	{
		false;
	}
	
	int leftDepth = 0;
	int rightDepth = 0;
	if (isBalanced(root->left, &leftDepth) && isBalanced(root->right, &rightDepth) )
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*depth = 1 + (left > right ? left : right);
			
			return true;
		}
	}
	
	return false;
}