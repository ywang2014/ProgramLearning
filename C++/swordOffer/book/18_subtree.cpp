/**
	树的子结构
	
	输入两颗二叉树A和B，判断B是不是A的子结构。
*/

// 二叉树节点的定义如下
struct TreeNode
{
	int value;
	TreeNode* l_child;
	TreeNode* r_child;
};

bool hasSubtree(TreeNode* root, TreeNode* subtreeRoot)
{
	bool result = false;
	if (root != NULL && subtreeRoot != NULL)
	{
		if (root->value == subtreeRoot->value)
		{
			result = doesTreeHaveSubtree(root, subtreeRoot);
		}
		
		if (!result)
		{
			result = hasSubtree(root->l_child, subtreeRoot);
		}
		
		if (!result)
		{
			result = hasSubtree(root->r_child, subtreeRoot);
		}
	}
	
	return result;
}

// 检验树A是否和树B同构
bool doesTreeHaveSubtree(TreeNode* root1, TreeNode* root2)
{
	if (root2 == NULL)
	{
		return true;
	}
	
	if (root1 == NULL)
	{
		return false;
	}
	
	if (root1->value != root2->value)
	{
		return false;
	}
	
	return doesTreeHaveSubtree(root1->l_child, root2->l_child) && doesTreeHaveSubtree(root1->r_child, root2->r_child);
}