/**
	树中两个节点的最低公共祖先
	
	这是一类多变形的题目，依据题目条件的不同，自然可以实现不同代码
	
	1. 二叉搜索树
	2. 普通二叉树，但有指向父节点的指针
	3. 普通树，没有指向父节点的指针
*/

// 题型二：普通二叉树，有指向父节点指针
struct BinaryTreeNode
{
	int value;
	
	BinaryTreeNode* parent;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* getCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* firstNode, BinaryTreeNode* secondNode)
{
	if (root == NULL || firstNode == NULL || secondNode == NULL)
	{
		return NULL;
	}
	
	int firstNodeDepth = getNodeDepth(root, firstNode);
	int secondNodeDepth = getNodeDepth(root, firstNode);
	
	int diff = firstNodeDepth - secondNodeDepth;
	bool firstPathLonger = true;
	if (firstNodeDepth < secondNodeDepth)
	{
		diff = secondNodeDepth - firstNodeDepth;
		firstPathLonger = false;
	}
	
	if (firstPathLonger)
	{
		alignByTrail(firstNode, diff);
	}
	else 
	{
		alignByTrail(secondNode, diff);
	}
	
	while (firstNode != NULL && firstNode != secondNode)
	{
		firstNode = firstNode->parent;
		secondNode = secondNode->parent;
	}
	
	return firstNode;
}


int getNodeDepth(BinaryTreeNode* root, BinaryTreeNode* node)
{
	if (root == NULL || firstNode == NULL)
	{
		return 0;	// invalid parameter
	}
	
	// 没有检查root并非node的根节点，非一棵树的异常情况
	
	BinaryTreeNode* currentNode = node;
	int depth = 0;
	while (currentNode != NULL)
	{
		depth++;
		currentNode = currentNode->parent;
	}
	
	return depth;
}


// 链表尾对齐函数
void alignByTrail(BinaryTreeNode* node, int diff)
{
	while (diff != 0)
	{
		node = node->parent;
		diff--;
	}
}