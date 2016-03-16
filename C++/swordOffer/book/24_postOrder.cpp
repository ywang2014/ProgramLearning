/**
	二叉搜索树的后序遍历序列
	
	题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true，否则返回false。
	假设输入的数组的任意两个数字都互不相同。
	
	思路：二叉搜索树是有序的，左子树的节点都小于根节点值，右子树的值都大于根节点值，所以可以根据序列的有序性，验证。
*/

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* l_child;
	BinaryTreeNode* r_child;
};


/******************* 参考代码 ******/
bool verifySequenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
	{
		return false;
	}
	
	int root = sequence[length - 1];
	
	// 在二叉搜索树中，左子树节点下于根节点
	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}
	
	// 在二叉搜索树中，右子树的节点大于根节点
	int j = i;
	for (; j < length - 1; ++j)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}
	
	// 判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
	{
		left = verifySequenceOfBST(sequence, i);
	}
	
	// 判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length - 1)
	{
		right = verifySequenceOfBST(sequence + i, length - i - 1);
	}
	
	return (left && right);
}


