/**
	将链表 a1->a2->a3->...->an->b1->b2->b3->...->bn重新排列成：
	a1->b1->a2->b2->...->an->bn 
	
	使用“快行指针”技巧，两个指针遍历链表
	
	输出中点，输出倒数第k个数，都可以使用快行指针
*/
class Node{
	Node front = null;
	Node rear = null; 
	int data;
}

Node realign(Node head){
	Node fast = head;	// 每次走两步
	Node slow = head;	// 每次走一步
	
	if (fast == null){
		return head;
	}
	while (fast.next != null){
		fast = fast.rear.rear;
		slow = slow.rear;
	}	
	// 此时fast指向尾节点，slow指向中点
	while (fast.front != head){
		fast = fast.front;
		Node p = slow;
		slow = deleteNode(slow);
		fast = insertNode(fast, p);
	}
	
	return head;
}

Node insertNode(Node p, Node q){
	q = p.rear;
	q.front = p;
	p.rear.front = q;
	p.rear = q;
	
	return p;
}

Node deleteNode(Node p){
	Node delNode = p;
	p = p->front;
	p->rear = delNode->rear;
	delNode->rear->front = p;
	
	return p;
}
