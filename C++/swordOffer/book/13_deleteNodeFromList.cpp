/**
	在O(1)的时间，删除链表的节点
	在给定单向链表的头指针和一个节点指针，定义一个函数，在O(1)时间删除该节点。链表节点和该函数定义如下
*/

struct ListNode
{
	int 	value;
	ListNode* next;
};	

// O(n)
void deleteNode(ListNode** listHead, ListNode* beDeleted)
{
	if (listHead == NULL || beDeleted == NULL)
	{
		return ;
	}
	
	ListNode* p = *listHead;
	while (p != NULL && p->next != beDeleted)
	{
		p = p->next;
	}
	
	if (p == NULL)
	{
		return ;	// 没有找到
	}
	
	// 删除
	p = p->next->next;
	delete beDeleted;
}

// O(1)时间复杂度
void deleteNode(ListNode** listHead, ListNode* beDeleted)
{
	if (listHead == NULL || beDeleted == NULL)
	{
		return ;
	}
	
	ListNode* p = *listHead;
	// 尾节点
	if (beDeleted->next == NULL)
	{
		// 只有一个节点情况
		if (p == beDeleted)
		{
			delete beDelted;
			listHead = NULL;
			return ;
		}
		
		while (p != NULL && p->next != beDeleted)
		{
			p = p->next;
		}
		
		if (p == NULL)	// 没有找到删除的元素
		{
			return ;
		}
		else
		{
			p->next = NULL;
			delete beDeleted;
		}
	}
	else	// O(1) 效率
	{
		ListNode* p = beDeleted->next;
		beDeleted->value = p->value;
		beDeleted->next = p->next;	// 删除p
		delete p;
	}
}


// 参考答案 源代码
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
	{
		return ;
	}
	
	// 删除的节点非尾节点
	if (pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		
		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDeleted)	// 只有一个节点情况
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else
	{
		// 多个节点，删除尾节点
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

