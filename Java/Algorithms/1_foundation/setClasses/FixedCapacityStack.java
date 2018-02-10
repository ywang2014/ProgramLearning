/**
	定容栈 	泛型
*/
public class FixedCapacityStack<Item>{
	private Item[] s;
	private int n;
	private int index;
	
	public FixedCapacityStack<Item>(int cap){
		n = cap;
		s = (Item[])new Obejct[n];
		index = 0;
	}
	
	public int size(){
		return index;
	}
	
	public boolean isEmpty(){
		return index == 0;
	}
	
	public void push(Item elem){
		s[index++] = elem;
	}
	
	public Item pop(){
		return index == 0 ? null : s[--index];
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