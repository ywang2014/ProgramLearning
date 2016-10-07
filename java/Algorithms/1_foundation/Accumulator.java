/**
	累加器的实现
*/
public class Accumulator{
	private double total;
	private int n;
	
	public void addDataValue(double val){
		n++;
		total += val;
	}
	
	public double mean(){
		return total / n;
	}
	
	public String toString(){
		return "Mean (" + n + " values): " + String.format("%7.5f", mean());
	}
	
	public static void main(String[] args){
		int T = Integer.parseInt(args[0]);
		Accumulator a = new Accumulator();
		for (int i = 0; i < T; i++){
			a.addDataValue(StdRandom.random());
		}
		StdOut.println(a);
	}
}