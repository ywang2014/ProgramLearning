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
		
		if (p == NULL)
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

