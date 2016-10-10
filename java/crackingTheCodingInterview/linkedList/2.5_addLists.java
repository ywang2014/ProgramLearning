/**
	给定两个链表表示的整数，每个结点包含一个数位，这些数位是反向存放的，
	即个位排在链表的头部。编写函数实现这两个整数求和，用链表形式返回结果。
*/

public static LinkedListNode addLists(LinkedListNode list1, LinkedListNode list2, int carry){
	if (list1 == null && list2 == null && carry == 0){
		return null;
	}
	
	LinkedListNode result = new LinkedListNode();
	int sum = carry;
	if (list1 != null){
		sum += list1.data;
	}
	if (list2 != null){
		sum += list2.data;
	}
	result.data = sum % 10;
	carry = sum / 10;
	result.next = addLists((list1 == null ? null : list1.next), 
		(list2 == null ? null : list2.next), carry);
		
	return result;
}


/**
	进阶：整数的数位是正常存放的，链表头存放最高位
*/
// 包裹类
public class PartialSum{
	public LinkedListNode sum = null;
	public int carry = 0;
}

LinkedListNode addLists(LinedListNode list1, LinkedListNode list2){
	int len1 = length(list1);
	int len2 = length(list2);
	
	if (len1 < len2){
		list1 = padList(list1, len2 - len1);
	}
	else{
		list2 = padList(list2, len1 - len2);
	}
	
	PartialSum sum = addListsHelper(list1, list2);
	if (sum.carry == 0){
		return sum.sum;
	}
	else{
		LinkedListNode result = insertBefore(sum.sum, sum.carry);
		return result;
	}
}

PartialSum addListsHelper(LinkedListNode list1, LinkedListNode list2){
	if (list1 == null && list2 == null){
		PartialSum sum = new PartialSum();
		return sum;
	}
	// 对小数位递归求和
	PartialSum sum = addListsHelper(list1.next, list2.next);
	int value = sum.carry + (list1 == null ? 0 : list1.data) + (list2 == null ? 0 : list2.data);
	// 插入当前数字的结果
	LinkedListNode full_result = insertBefore(sum.sum, value % 10);
	// 返回求和结果和进位值
	sum.sum = full_result;
	sum.carry = value / 10;
	return sum;
}

// 用零填充链表
LinkedListNode padList(LinkedListNode head, int padding){
	for (int i = 0; i < padding; i++){
		LinkedListNode node = new LinkedListNode(0, null, null);
		head.prev = node;
		node.next = head;
		head = node;
	}
	return head;
}

// 链表头部插入节点
LinkedListNode insertBefore(LinkedListNode head, int data){
	LinkedListNode node = new LinkedListNode(data, null, null);
	if (head != null){
		head.prev = node;
		node.next = head;
	}
	head = node;
	return head;
}