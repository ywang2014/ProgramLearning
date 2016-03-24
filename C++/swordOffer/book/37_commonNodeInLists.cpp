/**
	两个链表的第一个公共节点
	
	输入两个链表，找出它们的第一个公共节点。
*/

// 链表节点定义如下：
struct ListNode
{
	int value;
	ListNode* next;
};

ListNode* findFirstCommonNode(ListNode* firstHeadNode, ListNode* secondHeadNode)
{
	if (firstHeadNode == NULL || secondHeadNode == NULL)
	{
		return ;
	}
	
	int firstLength = 0;
	int secondLength = 0;
	ListNode* firstList = firstHeadNode;
	ListNode* secondList = secondHeadNode;
	
	while (firstList != NULL)
	{
		firstLength++;
		firstList = firstList->next;
	}
	
	while (secondList != NULL)
	{
		secondLength++;
		secondList = secondList->next;
	}
	
	firstList = firstHeadNode;
	secondList = secondHeadNode;
	while (firstLength < secondLength)
	{
		secondList = secondList->next;
		secondLength--;
	}
	
	while (firstLength > secondLength)
	{
		firstList = firstList->next;
		firstLength--;
	}
	
	while (firstList != NULL)
	{
		//if (firstList->value == secondList->value && firstList->next == secondList->next)
		if (firstList == secondList)
		{
			//return firstList;
			break;
		}
		
		firstList = firstList->next;
		secondList = secondList->next;
	}
	
	return firstList;
}


/*********************************** 参考代码 *********/
ListNode* findFirstCommonNode(ListNode* head1, ListNode* head2)
{
	// 得到两个链表的长度
	unsigned int len1 = getListLength(head1);
	unsigned int len2 = getListLength(head2);
	
	int lengthDif = len1 - len2;
	ListNode* headLong = head1;
	ListNode* headShort = head2;
	
	if (len1 < len2)
	{
		headLong = head2;
		headShort = head1;
		
		lengthDif = len2 - len1;
	}
	
	for (int index = 0; index < lengthDif; index++)
	{
		headLong = headLong->next;
	}
	
	while (headLong != NULL && headLong != headShort)
	{
		headLong = headLong->next;
		headShort = headShort->next;
	}
	
	return headLong;
}


unsigned int getListLength(ListNode* head)
{
	unsigned int len = 0;
	ListNode* node = head;
	
	while (node != NULL)
	{
		len++;
		node = node->next;
	}
	
	return len;
}
