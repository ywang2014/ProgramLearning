/**
	二叉树的深度
	
	输入一颗二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点(含根，叶节点)形成树的
	一条路径，最长的路径的长度为树的深度。
*/

// 二叉树的节点定义
struct BinaryTreeNode
{
	int Value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

int getDepthOfBinaryTree(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	int currentDepth = 0;
	int maxDepth = 0;
	
	getMaxDepth(root, currentDepth, maxDepth);
	
	return maxDepth;
}


// 递归过程中，直接修改currentDepth, maxDepth, 因此采用引用传参
void getMaxDepth(BinaryTreeNode* data, int& currentDepth, int& maxDepth)
{
	currentDepth ++;
	
	if (data->left == NULL && data->right == NULL)
	{
		maxDepth = (maxDepth < currentDepth ? currentDepth : maxDepth);
		
		//currentDepth--;
		
		return ;
	}
	
	if (data->left != NULL)
	{
		getMaxDepth(data, currentDepth, maxDepth);
		currentDepth--;
	}
	
	if (data->right != NULL)
	{
		getMaxDepth(data, currentDepth, maxDepth);
		currentDepth--;
	}
}


/********************** 参考代码 ***********/
int treeDepth(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	int leftDepth = treeDepth(root->left);
	int rightDepth = treeDepth(root->right);
	
	return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}