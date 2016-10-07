/**
	下压栈 链表实现
*/
public class ListStack<Item> implements Iterable<Item>{
	private Node first;
	private int n;
	
	private class Node{
		Item data;
		Node next;
	}
	
	public boolean isEmpty(){
		return first == null;
	}
	
	public int size(){
		return n;
	}
	
	public void push(Item elem){
		Node oldfirst = first;
		first = new Node();
		first.data = elem;
		first.next = oldfirst;
		n++;
	}
	
	public Item pop(){
		Item res = first.data;
		first = first.next();
		n--;
		 return res;
	}
	
	public Iterator<Item> iterator(){
		return new ListIterator();
	}
	
	private class ListIterator implements Iterator<Item>{
		private Node current = first;
		
		public boolean hasNext(){
			return current != null;
		}
		
		public Item next(){
			Item res = current.data;
			current = current.next();
			return res;
		}
	}
}