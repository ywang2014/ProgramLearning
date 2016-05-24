/**
	队列  链表实现
*/
public class ListQueue<Item> implements Iterable<Item>{
	private Node first;
	private Node last;
	private int n;
	
	private class Node{
		Item data;
		Node next;
	}
	
	public enqueue(Item elem){
		if (n == 0){
			last = new Node();
			last.data = elem;
			first = last;
		}
		else{
			Node oldlast = last;
			last = new Node();
			last.data = elem;
			oldlast.next = last;
		}
		n++;
	}
	
	public Item dequeue(){
		if (n == 0){
			return null;
		}
		Item res = first.data;
		if (n == 1){
			first = null;
			last = null;
		}
		else{
			first = first.next;
		}
		n--;
	}
	
	public boolean isEmpty(){
		return first == null;
	}
	
	public int size(){
		return n;
	}
	
	public Iterable<Item> iterator(){
		return new ListIterator<Item>();
	}
	
	private class ListIterator<Item> implements Iterable<Item>{
		private Node start = first;
		
		public boolean hasNext(){
			return start != null;
		}
		
		public Item next(){
			Item res = start.data;
			start = start.next;
			return res;
		}
	}
}