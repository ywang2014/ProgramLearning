/*
	链表
	
	动态内存分配、释放
*/

// 链表数据结构
struct ListNode
{
	int elem;
	LinkNode* next;
};


// 链表尾添加元素
void addToTail(ListNode** head, int value)
{
	ListNode* newNode = new ListNode();
	newNode->elem = value;
	newNode->next = NULL;
	
	ListNode* p = *head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	
	p->next = newNode;
}

void addToTail2(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->elem = value;
	pNew->next = NULL;
	
	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		
		while (pNode->next != NULL)
		{
			pNode = pNode->next;
		}
		
		pNode->next = pNew;
	}
}

// 在链表中，找到第一个含有某值的节点，并删除
void removeNode(ListNode** pHead, int value)
{
	if (*pHead == NULL)
	{
		return ;
	}
	
	ListNode* p = *pHead;
	
	// 第一个节点需要特别处理
	if (p->elem == value)	// 第一个节点就是
	{
		*pHead = p->next;
		delete p;
		return;
	}
	
	while (p->next != NULL && p->next->elem != value)
	{
		p = p->next;
	}
	
	if (p->next != NULL && p->next->elem == value)
	{
		ListNode* q = p->next;	// q就是要找的目标节点
		p->next = q->next;	// 链表中解除
		delete q;			// 内存释放
	}	
}

void removeNode2(ListNode** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
	{
		return ;
	}
	
	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->elem == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != NULL && pNode->next->elem != value)
		{
			pNode = pNode->next;
		}
		
		if (pNode->next != NULL && pNode->next->value == value)
		{
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}
	
	if (pToBeDeleted != NULL)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}