/**
	背包实现   链表
*/
import java.util,Iterator;

public class ListBag<Item> implements Iterable<Item>{
	private Node head;
	private int n;
	
	private class Node{
		Item data;
		Node next;
	}
	
	public void add(Item elem){
		Node oldfirst = first;
		first = new Node;
		first.data = elem;
		first.next = oldfirst;
		n++;
	}
	
	public boolean isEmpty(){
		return head == null;
	}
	
	public int size(){
		return n;
	}
	
	public Iterator<Item> iterator(){
		return new ListIterator();
	}
	
	private class ListIterator implements Iterator<Item>{
		private Node current = head;
		
		public boolean hasNext(){
			return current != null;
		}
		
		public Item next(){
			Item res = current.data;
			current = current.next;
			return res;
		}
		
		public void remove(){ }
	}
}