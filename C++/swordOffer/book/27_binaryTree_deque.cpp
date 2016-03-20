/**
	二叉搜索树与双向链表
	
	输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的节点，只能调整树中结点指针的
	指向。输出转换之后的排序双向链表。
	
	比如：输入二叉搜索树
	     10
	  6     14
	4  8 12  16
	输出：4 6 8 10 12 14 16
*/

// 二叉树节点的定义：
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void binaryTreeTransformDeque(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return ;
	}
}

/******************* 参考代码 **/
BinaryTreeNode* Convert(BinaryTreeNode* rootOfTree)
{
	BinaryTreeNode* lastNodeInList = NULL;
	convertNode(rootOfTree, &lastNodeInList);
	
	// lastNodeInList 指向双向链表的尾节点
	// 返回头结点
	BinaryTreeNode* headOfList = lastNodeInList;
	while (headOfList != NULL && headOfList->left != NULL)
	{
		headOfList = headOfList->left;
	}
	
	return headOfList;
}

void convertNode(BinaryTreeNode* node, BinaryTreeNode** lastNodeInList)
{
	if (node == NULL)
	{
		return ;
	}
	
	BinaryTreeNode* current = node;
	
	if (current->left != NULL)
	{
		convertNode(current->left, lastNodeInList);
	}
	
	current->left = *lastNodeInList;	// lastNodeList是当前节点的上一个节点
	if (*lastNodeInList != NULL)
	{
		(*lastNodeInList)->right = current;
	}
	
	*lastNodeInList = current;		// 一直在移动，遍历二叉树！
	
	if (current->right != NULL)
	{
		convertNode(current->right, lastNodeInList);
	}
}
