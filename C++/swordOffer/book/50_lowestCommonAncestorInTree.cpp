/**
	树中两个节点的最低公共祖先
	
	这是一类多变形的题目，依据题目条件的不同，自然可以实现不同代码
	
	1. 二叉搜索树
	2. 普通二叉树，但有指向父节点的指针
	3. 普通树，没有指向父节点的指针
*/

// 题型一：二叉搜索树
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* getCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* firstNode, BinaryTreeNode* secondNode)
{
	if (root == NULL || firstNode == NULL || secondNode == NULL)
	{
		return NULL;
	}
	
	int smallValue = firstNode->value;
	int bigValue = secondNode->value;
	
	if (smallValue > bigValue)
	{
		int oldSmallValue = smallValue;
		smallValue = bigValue;
		bigValue = oldSmallValue;
	}
	
	return getCommonAncestorRecursive(root, smallValue, secondValue);
}

BinaryTreeNode* getCommonAncestorRecursive(BinaryTreeNode* root, const int smallValue, int bigValue)
{
	if (root == NULL)
	{
		return NULL;
	}
	
	if (root->value < smallValue)
	{
		getCommonAncestorRecursive(root->right, smallValue, bigValue);
	}
	else if (bigValue < root->value)
	{
		getCommonAncestorRecursive(root->left, smallValue, bigValue);
	}
	
	// 值相等则直接返回该节点
	return root;
}