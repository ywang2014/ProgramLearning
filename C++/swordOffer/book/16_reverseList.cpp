/**
	反转链表
	
	定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
*/

// 链表节点定义如下：
struct ListNode
{
	int key;
	ListNode* next;
};

// 前端插入方法
ListNode* reverseList(ListNode* listHead)
{
	if (listNode == NULL)	// 空链表
	{
		return NULL;
	}
	// else if(listHead->next == NULL)
	// {
		// return listHead;
	// } 
	
	ListNode* currentNode = listHead->next;
	ListNode* insertNode = NULL;
	while (currentNode != NULL)
	{
		insertNode = currentNode;	// 取需要插入节点
		currentNode = insertNode->next;	// 移动到下一个待处理的节点
		
		insertNode->next = listHead;	// 表头插入
		listHead = insertNode;			// 恢复表头指针
	}
	
	return listHead;
}

/********** 参考代码 **/
ListNode* reverseList(ListNode* head)
{
	// if (head == NULL)
	// {
		// return NULL;
	// }
	// 循环中，可以解决此特例
	
	ListNode* currentNode = head;
	ListNode* prevNode = NULL;
	ListNode* nextNode = NULL;
	
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		
		prevNode = currentNode;
		currentNode = nextNode;
	}
	
	head = prevNode;
	
	return head;
}

// 直接反转链表中，在头插入，和将所有节点指针指向其前一个元素，本质一个意思！