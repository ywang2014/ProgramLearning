/**
	单向链表
*/
class Node{
	Node next = null;
	int data;
	
	public Node(int d){
		data = d;
	}
	
	void appendToTail(int d){
		Node end = new Node(d);
		Node n = this;
		while (n.next != null){
			n = n.next;
		}
		n.next = end;
	}
}

// 删除链表节点
Node deleteNode(Node head, int d){
	Node current = head;
	if (head.data == d){
		return head.next;	// 表头节点，指向下一个
	}
	while (current.next != null && current.next.data != d){
		current = current.next;
	}
	if (current.next != null){
		current.next = current.next.next;
	}
	
	return head;
}
