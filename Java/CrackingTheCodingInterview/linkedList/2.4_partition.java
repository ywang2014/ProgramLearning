/**
	以给定值x为基准，将链表分割成两部分，所有小于x的节点，排在大于或等于x的节点之前
*/
public LinkedListNode partition(LinkedListNode head, int x){
	LinkedListNode beforeStart = null;
	LinkedListNode beforeEnd = null;
	LinkedListNode afterStart = null;
	LinkedListNode afterEnd = null;
	
	LinkedListNode current = head;
	while (current != null){
		LinkedListNode next = current.next;
		current.next = null;
		if (current.data < x){
			if (beforeStart == null){
				beforeStart = current;
				beforeEnd = beforeStart;
			}
			else{
				beforeEnd.next = current;
				beforeEnd = beforeEnd.next;
			}
			// if (beforeStart == null){
				// beforeStart = current;
			// }
			// beforeEnd = current;
			// beforeEnd = beforeEnd.next;
		}
		else{
			if (afterStart == null){
				afterStart = current;
				afterEnd = afterStart;
			}
			else{
				afterEnd.next = current;
				afterEnd = afterEnd.next;
			}
		}
		current = next;
	}
	
	if (beforeStart == null){
		return afterStart;
	}
	beforeEnd.next = afterStart;
	return beforeStart;
}

/*------------------------------------------------*/
// 链表头插入
public LinkedListNode partition(LinkedListNode head, int x){
	LinkedListNode beforeStart = null;
	LinkedListNode afterStart = null;
	
	while (head != null){
		LinkedListNode next = node.next;
		if (head.data < x){
			head.next = beforeStart;
			beforeStart = head;
		}
		else{
			head.next = afterStart;
			afterStart = head;
		}
		head = next;
	}
	
	if (beforeStart == null){
		return afterStart;
	}
	
	head = beforeStart;
	while (beforeStart.next != null){
		beforeStart = beforeStart.next;
	}
	beforeStart.next = afterStart;
	
	return head;
}