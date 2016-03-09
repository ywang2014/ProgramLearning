/**
	链表中倒数第k个节点
	
	输入一个链表，输出该链表中的倒数第k个节点，为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第一个节点。
	例如：一个链表有六个节点，从头结点开始，它们的值依次是1/2/3/4/5/6.这个链表的倒数第三个节点是值为4的节点。
*/

struct ListNode
{
	int value;
	ListNode* next;
};

// 倒数第k个节点，就是顺数第 n-k+1 个节点。遍历两次链表即可实现

// 两个指针，只需要遍历一次链表
ListNode* findKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
	{
		return NULL;
	}
	
	ListNode* pFirst = pListHead;
	ListNode* pSecond = pListHead;
	while (pFirst->next != NULL && k != 0)
	{
		pFirst = pFirst->next;
		k--;
	}
	
	if (k != 0)	// 不足k个节点
	{
		return NULL;
	}
	
	while (pFirst->next != NULL)
	{
		pFirst = pFirst->next;
		pSecond = pSecond->next;
	}
	
	return pSecond;
	
}



