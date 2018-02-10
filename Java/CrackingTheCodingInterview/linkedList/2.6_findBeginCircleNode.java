/**
	给定一个有环的链表，实现一个算法，返回环路的开头节点
	
	快慢指针法：快指针一次走2步，慢指针一次走1步
		1.慢指针进去环时，快指针在其前面k个位置，k为链表非环节点数目
		2.慢指针在快指针前面：(loopsize-k)，显然再走(loopsize-k)步，两指针相遇
		3.第一次相遇时，两指针距离环路起点距离：k(loopsize-(loopsize-k))步.
		4.此时一个指针不动，一个指针指向链表头，同时一步一步向前移动，即同时到达环路起点处
*/
public static LinkedListNode findBeginCircleNode(LinkedListNode head){
	LinkedListNode slow = head;
	LinkedListNode fast = head;
	
	while (fast != null && fast.next != null){
		slow = slow.next;
		fast = fast.next.next;
		if (fast == slow){	// 第一次碰撞
			break;
		}
	}
	if (fast == null || fast.next == null){
		return null;
	}
	slow = head;
	while (slow != fast){
		slow = slow.next;
		fast = fast.next;
	}
	
	return fast;
}

