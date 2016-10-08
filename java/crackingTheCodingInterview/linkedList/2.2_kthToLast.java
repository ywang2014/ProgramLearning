/**
	2.2找出单向链表中倒数第k个节点
*/

// 递归方法--1
public static int kthToLast(LinkedListNode head, int k){
	if (head == null){
		return 0;
	}
	int i = kthToLast(head.next, k) + 1;
	if (i == k){
		System.out.println(head.data);
		// 静态全局变量即可实现存储
	}
	return i;
}

// 递归方法--2  C++
public static int kthToLast(LinkedListNode head, int k, int &i){
	if (head == nullptr){
		return nullptr;
	}
	node *nd = kthToLast(head->next, k, i);
	i++;
	if (i == k){
		return head;	// 递归函数，返回的是最后一次返回值，head将是最终的返回结果
	}
	return nd;
}


/*-------------------------------------------------------------*/
// 迭代法实现，两个指针
LinkedListNode kthToLast(LinkedListNode head, int k){
	if (k <= 0){
		return null;
	}
	LinkedListNode p1 = head;
	LinkedListNode p2 = head;
	while (p2 != null && k > 0){
		p2 = p2.next;
		k--;
	}
	
	if (p2 == null || k == 0){
		return null;
	}
	
	while (p2.next != null){
		p1 = p1.next;
		p2 = p2.next;
	}
	
	return p1;
}