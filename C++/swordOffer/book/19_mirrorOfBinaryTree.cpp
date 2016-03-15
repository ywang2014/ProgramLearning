/**
	二叉树的镜像
	
	请完成一个函数，输入一个二叉树，该函数输出该二叉树的镜像！
*/

// 二叉树的定义
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void mirror(BinaryTreeNode* treeRoot)
{
	if (treeRoot == NULL)
	{
		return ;
	}
	
	if (treeRoot->left == NULL && treeRoot->right == NULL)
	{
		return ;
	}
	
	// 即使有空子树，也不影响
	BinaryTreeNode* pLeft = treeRoot->left;
	BinaryTreeNode* pRight = treeRoot->right;
	
	// 交换左右子树
	treeRoot->left = pRight;
	treeRoot->right = pLeft;
	
	// 递归操作子树
	mirror(treeRoot->left);
	mirror(treeRoot->right);
}

/****************************** 参考代码	**/
void mirrorRecursively(BinaryTreeNode* pNode)
{
	if (pNode == NULL || (pNode->left == NULL && pNode->right == NULL))
	{
		return ;
	}
	
	BinaryTreeNode* pTemp = pNode->left;
	pNode->left = pNode->right;
	pNode->right = pTemp;
	
	if (pNode->left)
	{
		mirrorRecursively(pNode->left);
	}
	
	if (pNode->right)
	{
		mirrorRecursively(pNode->right);
	}
}

// 循环实现，则必须使用队列保存遍历过程中，有左子树的节点，用于回溯，遍历其右子树
