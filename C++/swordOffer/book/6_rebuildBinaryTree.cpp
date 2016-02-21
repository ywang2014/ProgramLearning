/*
	重建二叉树
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
{1,2,4,7,3,5,6,8}和中序遍历虚列{4,7,2,1,5,3,8,6}，则重建出如图的二叉树，并输出它的头结点。

*/

// 二叉树节点定义
struct BinaryTreeNode
{
	int 			m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode*	m_pRight;
};

// 创建节点
BinaryTreeNode* createNode(int n)
{
	BinaryTreeNode* newNode = new BinaryTreeNode;
	if (newNode == NULL)
	{
		return NULL;
	}
	
	newNode->m_nValue = n;
	newNode->m_pLeft = NULL;
	newNode->m_pRight = NULL;
	
	return newNode;
}

// 查找节点元素在序列中的位置函数, 没有找到，则返回-1
int findElem(const int* arr, const int n, const int value)
{
	if (arr == NULL || n < 1)
	{
		return -1;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	
	return -1;
}


BinaryTreeNode* rebuildBinaryTree(int* front, int f_lo, int f_hi, int* mid, int m_lo, int m_hi)
{
	if (front == NULL || mid == NULL)
	{
		return NULL;
	}
	
	if (f_lo == f_hi || f_lo > f_hi || m_lo == m_hi || m_lo > m_hi)
	{
		return NULL;
	}
	
	BinaryTreeNode* root = createNode(front[0]);
	
	int site = findElem(mid, m_hi - m_lo, front[0]);
	
	// 左树：front[1,site] mid[0,site-1]	右树: front[site+1, n) mid[site+1,n)
	// 直接递归处理
	root->m_pLeft = rebuildBinaryTree(front, f_lo+1, site+1, mid, m_lo, site);
	root->m_pRight = rebuildBinaryTree(front, site, f_hi, mid, site+1, m_hi);
	
	return root;
}

/*********************************** 调试正确
#include <iostream>

using namespace std;

// 二叉树节点定义
struct BinaryTreeNode
{
	int 			m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode*	m_pRight;
};

// 创建节点
BinaryTreeNode* createNode(int n)
{
	BinaryTreeNode* newNode = new BinaryTreeNode;
	if (newNode == NULL)
	{
		return NULL;
	}

	newNode->m_nValue = n;
	newNode->m_pLeft = NULL;
	newNode->m_pRight = NULL;

	return newNode;
}

// 查找节点元素在序列中的位置函数, 没有找到，则返回-1
int findElem(const int* arr, const int lo, const int hi, const int value)
{
	if (arr == NULL)
	{
		return -1;
	}

	for (int i = lo; i < hi; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}

	return -1;
}


BinaryTreeNode* rebuildBinaryTree(const int* front, int f_lo, int f_hi, const int* mid, int m_lo, int m_hi)
{
	if (front == NULL || mid == NULL)
	{
		return NULL;
	}

	if (f_lo == f_hi || f_lo > f_hi || m_lo == m_hi || m_lo > m_hi)
	{
		return NULL;
	}

	BinaryTreeNode* root = createNode(front[f_lo]);

	int site = findElem(mid, m_lo, m_hi, front[f_lo]);

	// 左树：front[1,site] mid[0,site-1]	右树: front[site+1, n) mid[site+1,n)  不能使用site简单的处理，除非每次复制到了新的数组
	// 直接递归处理
	root->m_pLeft = rebuildBinaryTree(front, f_lo+1, site - m_lo + f_lo + 1, mid, m_lo, site);  // 关系一定要计算清楚
	root->m_pRight = rebuildBinaryTree(front, f_hi - m_hi + site + 1, f_hi, mid, site+1, m_hi);

	return root;
}

int main()
{
    int arr1[8] = {1,2,4,7,3,5,6,8};
    int arr2[8] = {4,7,2,1,5,3,8,6,};

    BinaryTreeNode* root = rebuildBinaryTree(arr1, 0, 8, arr2, 0, 8);

    cout << root->m_nValue << " " << root->m_pLeft->m_nValue << " " << root->m_pRight->m_nValue;
    return 0;
}

************************************************/

// 参考答案
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return NULL;
	}
	
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int*startInorder, int* endInorder)
{
	int value = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = value;
	root->m_pLeft = root->m_pRight = NULL;
	
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
		{
			return root;
		}
		else
		{
			throw std::exception("Invalid input");
		}
	}
	
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != value)
	{
		rootInorder++;
	}
	
	//if (rootInorder == endInorder && *rootInorder != value)
	if (rootInorder > endInorder || *rootInorder != value)
	{
		throw std::exception("Invalid input.");
	}
	
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	
	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInoreder + 1, endInorder);
	}
	
	return root;
}