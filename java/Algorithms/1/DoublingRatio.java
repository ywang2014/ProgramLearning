/**
	experiment test 
*/
public class DoublingRatio{
	public static double timeTrial(int n){
		int[] a = new int[n];
		for (int i = 0; i < n; i++){
			a[i] = StdRandom.unique(-1000000, 1000000);
		}
		long timer = System.currentTimeMills();
		// TODO
		
		return (System.currentTimeMills() - timer) / 1000.0;
	}
	
	public static void main(String[] args){
		double prev = timeTrial(125);
		for (int n = 250; true; n += n){
			double time = timeTrial(n);
			StdOut.printf("%6d %7.1f ", n, time);
			StdOut.printf("%5.1f\n", time / prev);
			prev = time;
		}
	}
}