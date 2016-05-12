/**
	删除链表中的重复节点
*/
// 借助哈希表实现的 时间复杂度：O(n)
public static void deleteDups(LinkedListNode head){
	Hashtable table = new Hashtable();
	LinkedListNode previous = null;
	LinkedListNode current = head;
	
	while (current != null){
		if (table.containsKey(current.data)){
			previous.next = current.next;
		}
		else {
			table.put(current.data, true);
			previous = current;
		}
		current = current.next;
	}
}

// 不借助缓冲区，时间复杂度O(n^2)，空间复杂度O(1)
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
			}
			else{
				runner = runner.next;
			}
		}
		current = current.next;
	}
}