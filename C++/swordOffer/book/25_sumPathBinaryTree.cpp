/**
	二叉树中和为某一值的路径
	
	输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树根节点开始往下一直到叶节点，
	所经过的节点形成一条路径。
*/
// 二叉树节点的定义如下：
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* l_child;
	BinaryTreeNode* r_child;
};

void printPath(BinaryTreeNode* root, int number)
{
	if (root == NULL)
	{
		return ;
	}
	
	printf("%d ", root->value);
	
	number -= root->value;
	
	if (root->l_child == NULL && root->r_child == NULL)
	{
		if (number == 0)
		{
			printf("Ok\n");
		}
		else
		{
			printf("No\n");
		}
		
		return ;	// 递归退出条件
	}
	
	if (root->l_child != NULL)
	{
		printPath(root->l_child, number);
	}
	
	if (root->r_child != NULL)
	{
		printPath(root->r_child, number);
	}
}

/************************ 参考源代码  	**/
void findPath(BinaryTreeNode* root, int expectedSum)
{
	if (root == NULL)
	{
		return ;
	}
	
	std::vector<int> path;
	int currentSum = 0;
	
	findPathRecursive(root, expectedSum, path, currentSum);
}

void findPathRecursive
(
	BinaryTreeNode* root,
	int expectedSum,
	std::vector<int>& path,
	int currentSum 
)
{
	currentSum += root->value;
	path.push_back(root->value);
	
	bool isLeaf = (root->l_child == NULL && root->r_child == NULL);
	if (isLeaf && currentSum == expectedSum)
	{
		printf("A path is found: ");
		typedef std::vector<int>::const_iterator CIT;
		for (CIT iter = path.begin(); iter != path.end(); ++iter)
		{
			printf("%d ", *iter);
		}
		printf("\n");

		return ;
	}
	
	if (root->l_child != NULL)
	{
		findPathRecursive(root->l_child, expectedSum, path, currentSum);
	}
	
	if (root->r_child != NULL)
	{
		findPathRecursive(root->r_child, expectedSum, path, currentSum);
	}
	
	currentSum -= root->value;
	path.pop_back();
}
