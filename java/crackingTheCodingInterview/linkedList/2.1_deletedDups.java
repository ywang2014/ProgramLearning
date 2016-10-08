/**
	2.1 编写代码，移除未排序链表中的重复结点
*/
public static void deleteDups(LinkedListNode n){
	Hashtable table = new Hashtable();
	LinkedListNode previous = null;
	while (n != null){
		if (table.containsKey(n.data)){
			previous.next = n.next;	// n已经先一步到了next，此时实际为：n.next.next
		}
		else{
			table.put(n.data, true);
			previous = n;	// 第二次及以后，等价于：previous = previous.next;
		}
		n = n.next;
	}
}

public static void deleteDups(LinkedListNode head){
	if (head == null){
		return ;
	}
	Hashtable table = new Hashtable();
	LinkedListNode current = head;
	table.put(current.data, true);
	while (current != null && current.next != null){
		if (table.containsKey(current.next.data)){
			current.next = current.next.next;
		}
		else{
			table.put(current.next.data, true);
		}
		current = current.next;
		// 当遇到重复结点时，这样实际多跳了一步，正确做法是下面的方法
	}
}

// 不使用额外的缓冲区，两个指针实现删除重复结点
public static void deleteDups(LinkedListNode head){
	if (head == null){
		return ;
	}
	
	LinkedListNode current = head;
	while (current != null){
		LinkedListNode runner = current;
		while (runner.next != null){
			if (runner.next.data == current.data){
				runner.next = runner.next.next;
				// 此时runner.next已经修改了，不需要向后移动
			}
			else{
				runner = runner.next;
			}
		}
		current = current.next;
	}
}