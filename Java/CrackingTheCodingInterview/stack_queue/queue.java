/**
	队列的实现
*/
class Queue{
	Node first;
	Node last;
	
	void enqueue(Object item){
		Node n = new Node(item);
		if (first = null){
			first = last = n;
		}
		else{
			last.next = n;
			last = n;
		}
	}
	
	void dequeue(){
		if (first == null){
			return ;
		}
		first = first.next;
	}
	
	Object front(){
		if (first == null){
			return null;
		}
		
		return first.data;
	}
}