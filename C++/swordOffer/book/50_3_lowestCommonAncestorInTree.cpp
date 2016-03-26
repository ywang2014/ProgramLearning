/**
	树中两个节点的最低公共祖先
	
	这是一类多变形的题目，依据题目条件的不同，自然可以实现不同代码
	
	1. 二叉搜索树
	2. 普通二叉树，但有指向父节点的指针
	3. 普通树，没有指向父节点的指针
*/

// 题型三：普通二叉树，没有指向父节点指针
struct BinaryTreeNode
{
	int value;
	
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};


BinaryTreeNode* g_CommonNode = NULL;	// 此节点即最低公共祖先
void getCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* firstNode, BinaryTreeNode* secondNode)
{
	if (root == NULL || firstNode == NULL || secondNode == NULL)
	{
		return ;
	}
	
	if ( includeTwoNodes(root, firstNode, secondNode) )
	{
		g_CommonNode = root;
		getCommonAncestor(root->left, firstNode, secondNode);
		getCommonAncestor(root->right, firstNode, secondNode);
	}
	
}


bool includeTwoNodes(BinaryTreeNode* root, BinaryTreeNode* firstNode, BinaryTreeNode* secondNode)
{
	if (root == NULL || firstNode == NULL || secondNode == NULL)
	{
		return false;
	}
	
	bool isInclude = false;
	
	isIncludeNode(root, firstNode, isInclude);
	isIncludeNode(root, secondNode, isInclude);
	
	return isInclude;
}


// bool isIncludeNode(BinaryTreeNode* root, BinaryTreeNode* node)
// 递归函数不能依赖于其返回值，返回值仅是最后一次函数的返回值。因此只能借助于标记位

void isIncludeNode(BinaryTreeNode* root, BinaryTreeNode* node, bool& isInclude)
{
	if (root == NULL || node == NULL)
	{
		return ;
	}
	
	if (root == node)
	{
		isInclude = true;
		return ;
	}
	else 
	{
		if (root->left != NULL)
		{
			isIncludeNode(root->left, node, isInclude);
		}
		
		if (root->right != NULL)
		{
			isIncludeNode(root->right, node, isInclude);
		}
	}
}


/******************** 参考代码 **********/
// 借助辅助内存，实现高效算法，保存访问的路径，即两个链表
bool getNodePath(TreeNode* root, TreeNode* node, list<TreeNode*>& path)
{
	if (root == NULL)
	{
		return false;
	}
	
	path.push_back(root);
	
	if (root == node)
	{
		return true;
	}
	
	bool found = false;
	
	// 很多孩子节点，故需要while一个一个遍历，依次递归访问
	vector<TreeNode*>::iterator it = root->children.begin();
	while (!found && it < root->children.end())
	{
		found = getNodePath(*it, node, path);
		it++;
	}
	
	if (!found)
	{
		path.pop_back();
	}	
	
	return found;
}


TreeNode* getLastCommonNode(
	const list<TreeNode*>& path1,
	const list<TreeNode*>& path2
	)
{
	list<TreeNode*>::const_iterator it1 = path1.begin();
	list<TreeNode*>::const_iterator it2 = path2.begin();
	
	TreeNode* lastNode = NULL;
	
	// 根节点相同，即前面的节点，都相同
	while (it1 != path1.end() && it2 != path2.end() && *it1 == *it2)
	{
		lastNode = *it1;
		
		it1++;
		it2++;
	}
	
	return last;
}


TreeNode* getLastCommonParent(
	TreeNode* root,
	TreeNode* node1,
	TreeNode* node2
	)
{
	if (root == NULL || node1 == NULL || node2 == NULL)
	{
		return NULL;
	}
	
	list<TreeNode*> path1;
	getNodePath(root, node1, path1);
	
	list<TreeNode*> path2;
	getNodePath(root, node2, path2);
	
	return getLastCommonNode(path1, path2);
}