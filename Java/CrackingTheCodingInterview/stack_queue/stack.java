/**
	栈的实现
*/
class Stack{
	Node top;
	
	Object pop(){
		if (top != null){
			Object item = top.data;
			top = top.next;
			return item;
		}
		return null;
	}
	
	void push(Object item){
		Node t = new Node(item);
		t.next = top;
		top = t;
	}
	
	Object peek(){
		return top.data;
	}
}

class Node{
	Node next = null;
	Object data;
	
	public Node(Object item){
		data = item;
	}
}