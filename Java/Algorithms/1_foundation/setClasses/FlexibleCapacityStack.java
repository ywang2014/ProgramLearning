/**
	弹性栈 	泛型
*/
public class FlexibleCapacityStack<Item>{
	private Item[] s;
	private int n;
	private int index;
	
	private void resize(int max){
		Item[] tmp = (Item[]) new Object[max];
		for (int i = 0; i < index; i++){
			tmp[i] = s[i];
		}
		s = tmp;
	}
	
	public FlexibleCapacityStack<Item>(int cap){
		n = cap;
		s = (Item[]) new Obejct[n];
		index = 0;
	}
	
	public int size(){
		return index;
	}
	
	public boolean isEmpty(){
		return index == 0;
	}
	
	public void push(Item elem){
		if (index == n){
			resize(2 * n);
		}
		s[index++] = elem;
	}
	
	public Item pop(){
		if (index == 0){
			return null;
		}
		
		Item res = s[--index];
		
		if (index < n / 4){
			resize(n / 2);
		}
		
		return res;
	}
	
	public static void main(String[] args){
		FixedCapacityStack<String> s = new FixedCapacityStack<String>(100);
		while (!StdIn.isEmpty()){
			String item = StdIn.readString();
			if (!item.equals("-")){
				s.push(item);
			}
			else if (!s.isEmpty()){
				StdOut.print(s.pop() + " ");
			}
		}
		StdOut.println("(" + s.size() + " left on stack)");
		
	}
}