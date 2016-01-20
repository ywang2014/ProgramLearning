/*
	求链表中的倒数第k个节点
	两个指针
*/

ListNode* findKth2Tail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL)	// 空指针
	{
		return NULL;
	}
	
	if (k < 1)	// k值不合法
	{	
		return NULL;
	}
	
	unsigned int index = 0;
	ListNode* pAhead = pListHead;
	ListNode* pBehind = pListHead;
	while (pAhead->next != NULL && index < (k-1))	// 移动k-1次
	{
		pAhead = pAhead->next;
		index++;
	}
	
	if (pAhead->next == NULL && (index < (k - 1)))	// 节点数小于k
	{
		return NULL;
	}
	
	while (pAhead->next != NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	
	return pBehind;
}