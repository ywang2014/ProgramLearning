/**
	合并两个排序链表
	
	输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然按照递增排序。
	
	例如链表1:	1 3 5 7，链表2：	2 4 6 8
	合并后：	1 2 3 4 5 6 7 8

*/

// 链表节点定义：
struct ListNode
{
	int value;
	ListNode* next;
};

ListNode* merge2Lists(ListNode* firstHead, ListNode* secondHead)
{
	if (firstHead == NULL && secondHead == NULL)
	{
		return NULL;
	}
	else if (firstHead == NULL)
	{
		return secondHead;
	}
	else if (secondHead == NULL)
	{
		return firstHead;
	}
	
	// ListNode* newHead = (listHead1->value < listHead2->value) ? listHead1 : listHead2;
	ListNode* newHead = NULL;
	if (firstHead->value < secondHead->value)
	{
		newHead = firstHead;
		firstHead = firstHead->next;
	}
	else
	{
		newHead = secondHead;
		secondHead = secondHead->next;
	}
	
	ListNode* currentTail = newHead;	// 指向链表尾节点
	while (firstHead || secondHead)
	{
		while (firstHead && (secondHead == NULL || firstHead->value < secondHead->value))
		{
			currentTail->next = firstHead;
			currentTail = currentTail->next;
			firstHead = firstHead->next;
		}
		
		while (secondHead && (firstHead == NULL || secondHead->value < firstHead->value))
		{
			currentTail->next = secondHead;
			currentTail = currentTail->next;
			secondHead = secondHead->next;
		}
	}
	
	return newHead;
}

/************************ 参考代码 **/
ListNode* merge(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	
	ListNode* mergeHead = NULL;
	
	if (head1->value < head2->value)
	{
		mergeHead = head1;
		mergeHead->next = merge(head1->next, head2);
	}
	else 
	{
		mergeHead = head2;
		mergeHead->next = merge(head1, head2->next);
	}
	
	return mergeHead;
}

// 递归代码，非常简单，巧妙
