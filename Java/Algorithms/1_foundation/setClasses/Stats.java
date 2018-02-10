/**
	统计输入中数字的均值和标准差
	背包的用例
*/
public class Stats{
	public static void main(String[] args){
		Bag<Double> numbers = new Bag<Double>();
		while (!StdIn.isEmpty()){
			numbers.add(StdIn.readDouble());
		}
		
		int n = numbers.size();
		double sum = 0.0;
		for (double elem : numbers){
			sum += elem;
		}
		double mean = (n == 0 ? 0 : sum / n);
		
		sum = 0.0;
		for (double elem : numbers){
			sum += (elem - mean) * (elem - mean);
		}
		double std = Math.sqrt(sum / (n - 1));	// n > 1
		
		StdOut.printf("Mean: %.2f\n", mean);
		StdOut.printf("Std dev: %.2f\n", std);
	}
}