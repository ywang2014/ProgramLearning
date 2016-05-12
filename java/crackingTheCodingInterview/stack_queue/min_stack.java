/**
	栈的实现
	
	包含 min方法
*/
class Stack{
	Node top;
	Node minData;
	
	Object pop(){
		if (top != null){
			Object item = top.data;
			top = top.next;
			minData = minData.next;
			
			return item;
		}
		return null;
	}
	
	void push(Object item){
		Node t = new Node(item);
		t.next = top;
		top = t;
		
		// minData存储当前最小值
		if (minData != null && minData.data < item){
			Node min = new Node(minData.data);
			min.next = minData;
			minData = min;
		}
		else{
			t.next = minData;
			minData = t;
		}
	}
	
	Object peek(){
		return top.data;
	}
	
	Object min(){
		return minData.data;
	}
}

class Node{
	Node next = null;
	Object data;
	
	public Node(Object item){
		data = item;
	}
}