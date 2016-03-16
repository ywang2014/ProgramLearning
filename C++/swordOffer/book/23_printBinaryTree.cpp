/**
	从上往下打印二叉树
	
	从上往下打印出二叉树的每个节点，同一层的节点按照从左往右的顺序打印。
	
	例如：
			  8
		  6      10
		5   7   9  11
	输出：8 6 10 5 7 9 11 
	
	思路：借助队列，存储访问过的节点，顺序打印即可
*/

// 二叉树节点的定义：
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* l_child;
	BinaryTreeNode* r_child;
};

#include <queue>

void printBinaryTree(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	
	std::queue<BinaryTreeNode*> que;
	BinaryTreeNode* nextNode = root;
	
	que.push(nextNode);
	
	while (que.size() != 0)
	{
		nextNode = que.front();
		que.pop();
		
		printNode(nextNode);
		
		if (nextNode->l_child != NULL)
		{
			que.push(nextNode->l_child);
		}
		
		if (nextNode->r_child != NULL)
		{
			que.push(nextNode->r_child);
		}
	}
}

/****************************** 参考代码		**/
void printFromTopToBottom(BinaryTreeNode* treeRoot)
{
	if (! treeRoot)
	{
		return ;
	}
	
	std::deque<BinaryTreeNode*> dequeTreeNode;
	
	dequeTreeNode.push_back(treeRoot);
	
	while (dequeTreeNode.size())
	{
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		
		printf("%d ", pNode->value);
		
		if (pNode->l_child)
		{
			dequeTreeNode.push_back(pNode->l_child);
		}
		
		if (pNode->r_child)
		{
			dequeTreeNode.push_back(pNode->r_child);
		}
	}
}
