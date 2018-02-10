/**
	VisualAccumulator
*/
public class VisualAccumulator{
	private double total;
	private int n;
	
	public VisualAccumulator(int trials, double max){
		StdDraw.setXscale(0, trials);
		StdDraw.setYscale(0, max);
		StdDraw.setPenRadius(0.005);
	}
	
	public void addDataValue(double val){
		n++;
		total += val;
		StdDraw.setPenColor(StdDraw.DARK_GRAY);
		StdDraw.point(n, val);
		StdDraw.setPenColor(StdDraw.RED);
		StdDraw.point(n, total / n);
	}
	
	public double mean(){
		return total / n;
	}
	
	public String toString(){
		return "Mean (" + n + " values): " + String.format("%7.5f", mean());
	}
	
	public static void main(String[] args){
		int T = Integer.parseInt(args[0]);
		VisualAccumulator a = new VisualAccumulator(T, 1.0);
		for (int t = 0; t < T; t++){
			a.addDataValue(StdRandom.random());
		}
		StdOut.println(a);
	}
}