/**
	复杂链表的复制
	
	请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复制一个复杂链表。在复杂链表中，每一个节点除了有一个
	m_pNext指针指向下一个节点外，还有一个m_pSibling指向链表中的任意节点或者NULL。
*/
// 节点的C++定义如下：
struct ComplexListNode
{
	int value;
	ComplexListNode* next;
	ComplexListNode* sibling;
};

/*
	方法一：O(n^2)
	复制链表，仅处理next指针，第二步复制sibling指针。
	每次遍历链表，找到相应的节点，即可完成。
*/

/*
	方法二：O(n)时间 + O(n)空间
	借助hash表，快速定位每一个节点。
	也是第一步复制简单链表，然后再处理sibling指针
*/

/*
	方法三：O(n)时间 + O(n)空间
	第一步复制简单链表，并同时创建节点A的复制节点A‘，使用next指针链接
	第二步复制sibling指针，A->S，则A'->S'.
	第三步，拆分成两个链表，即实现复制了。
*/

void cloneNodes(ComplexListNode* head)
{
	ComplexListNode* node = head;
	while (node != NULL)
	{
		ComplexListNode* cloned = new ComplexListNode();	// 节点
		cloned->value = node->value;
		cloned->next = node->next;
		cloned->sibling = NULL;
		
		node->next = cloned;	// 修改指针
		
		node = cloned->next;	// 迭代
	}
}

void connectsiblingNodes(ComplexListNode* head)
{
	ComplexListNode* node = head;
	while (node != NULL)
	{
		ComplexListNode* clone = node->next;	// 指针
		if (node->sibling != NULL)
		{
			cloned->sibling = node->sibling->next;
		}
		
		node = cloned->next;
	}
}

ComplexListNode* reconnectNodes(ComplexListNode* head)
{
	ComplexListNode* node = head;
	clonedHead = NULL;
	clonedNode = NULL;
	
	if (node != NULL)
	{
		clonedHead = clonedNode = node->next;
		node->next = clonedNode->next;
		node = node->next;
	}
	
	while (node != NULL)
	{
		clonedNode->next = node->next;
		clonedNode = clonedNode->next;
		node->next = clonedNode->next;
		node = node->next;
	}
	
	return clonedHead;
}


ComplexListNode* clone(ComplexListNode* head)
{
	cloneNodes(head);
	connectsiblingNodes(head);
	return reconnectNodes(head);
}