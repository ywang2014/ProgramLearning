/**
	栈 LIFO
*/
public class Stack<Item> implements Iterable<Item>{
	public Stack();
	public void push(Item elem);
	public Item pop();
	public boolean isEmpty();
	public int size();
}