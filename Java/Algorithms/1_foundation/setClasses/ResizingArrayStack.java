/**
	下压栈   动态调整数组的大小
*/
import java.util.Iterator;
public class ResizingArrayStack<Item> implements Iterable<Item>{
	private Item[] s = (Item[]) new Object[1];
	private int n = 0;
	
	public boolean isEmpty(){
		return n == 0;
	}
	
	public int size(){
		return n;
	}
	
	private void resize(int max){
		Item[] temp = (Item[]) new Object[max];
		for (int i = 0; i < n; i++){
			temp[i] = s[i];
		}
		s = temp;
	}
	
	public void push(Item elem){
		if (n == s.length){
			resize(2 * s.length);
		}
		s[n++] = elem;
	}
	
	public Item pop(){
		Item res = s[--n];
		s[n] = null;	// 避免对象游离
		if (n > 0 && n == s.length / 4){
			resize(s.length / 2);
		}
		return res;
	}
	
	public Iterator<Item> iterator(){
		return new ReverseArrayIterator();
	}
	
	private class ReverseArrayIterator implements Iterator<Item>{
		private int i = n;
		
		public boolean hasNext(){
			return i > 0;
		}
		
		public Item next(){
			return s[--i];
		}
		
		public void remove(){ }
	}
}