/**
	定容栈
*/
public class FixedCapacityStackOfStrings{
	private String[] s;
	private int n;
	private int index;
	
	public FixedCapacityStackOfStrings{int cap){
		n = cap;
		s = new String[n];
		index = 0;
	}
	
	public void push(String item){
		if (index != n){
			s[index++] = new String(item);
		}
	}
	
	public String pop(){
		return index == 0 ? null : s[--index];
	}
	
	public boolean isEmpty(){
		return index == 0;
	}
	
	public int size(){
		return index;
	}
	
	public static void main(String[] args){
		FixedCapacityStackOfStrings s = new FixedCapacityStackOfStrings(100);
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