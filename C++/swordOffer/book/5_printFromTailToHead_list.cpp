/*
	从尾到头打印链表
	输入一个链表的头结点，从未到头反过来打印出每个节点的值
*/

struct ListNode
{
	int key;
	ListNode* next;
};

void printFromTail2Head(const ListNode* head)
{
	// 思路一：一个vector，把所有的值存储起来，然后打印下标直接逆序打印即可，时间复杂度：O(n)
	// 思路二：新建一个链表，从链表头插入，即将原链表翻转一次，然后顺序打印，时间复杂度：O(n)
}

// 答案使用栈实现顺序反转
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;
	
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}
	
	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->key);
		nodes.pop();
	}
}

// 基于递归的方法，巧妙！！！！
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->next != NULL)
		{
			PrintListReversingly_Recursively(pHead->next);
		}
		else
		{
			// 放在递归调用后面输出，就是栈结构，先进后出
			// 如果放在前面，就是顺序结构，先进先出
			printf("%d\t", pHead->key);
		}
	}
}
