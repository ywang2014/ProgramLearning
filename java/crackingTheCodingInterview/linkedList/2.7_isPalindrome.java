/**
	检查链表是否为回文
*/
boolean isPalindrome(LinkedListNode head){
	LinkedListNode fast = head;
	LinkedListNode slow = head;
	Stack<Integer> stack = new Stack<Integer>();
	
	while (fast != null && fast.next != null){
		stack.push(slow.data);
		slow = slow.next;
		fast = fast.next.next;
	}
	// 奇数个节点，跳过中间节点
	if (fast != null){
		slow = slow.next;
	}
	while (slow != null){
		int top = stack.pop().intValue();
		if (top != slow.data){
			return false;
		}
		slow = slow.next;
	}
	return true;
}

// 翻转链表，再比较
boolean isPalindrome(LinkedListNode head){
	// 第一步，反转链表
	LinkedListNode current = head;
	LinkedListNode newHead = null;
	while (current != null){
		LinkedListNode node = new LinkedListNode(current);
		node.next = newHead;
		newHead = node;
		current = current.next;
	}
	
	while (newHead != null){
		if (newHead.data != head.data){
			return false;
		}
		newHead = newHead.next;
		head = head.next;
	}
	
	return true;
}

// 递归版本
class Result{
	public LinkedListNode node;
	public boolean result;
}

Result isPalindromeRecurse(LinkedListNode head, int length){
	if (head == null || length == 0){
		return new Result(null, true);
	}
	else if (length == 1){
		return new Result(head.next, true);
	}
	else if (length == 2){
		return new Reuslt(head.next.next, head.data == head.next.data);
	}
	
	Result res = isPalindromeRecurse(head.next, length - 2);
	if (!res.result || res.node == null){
		return res;	// 说明，false时，此后不再修改res了，高明
	}
	else{
		res.result = head.data == res.node.data;
		res.node = res.node.next;
		return res;
	}
}

boolean isPalindrome(LinedListNode head){
	Result p = isPalindromeRecurse(head, listSize(head));
	return p.result;
}