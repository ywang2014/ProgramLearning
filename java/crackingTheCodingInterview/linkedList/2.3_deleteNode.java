/**
	删除单向链表中间的某个节点，假定你只能访问该节点
*/
public static boolean deleteNode(LinkedListNode node){
	if (node == null || node.next == null){
		return false;
	}
	node.data = node.next.data;
	node.next = node.next.next;
	return true;
}