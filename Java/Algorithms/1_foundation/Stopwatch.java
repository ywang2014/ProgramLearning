/**
	计时器   currentTimeMillis()
*/
public class Stopwatch{
	private final long start;
	
	public Stopwatch(){
		start = System.currentTimeMills();
	}
	
	public double elapsedTime(){
		long now = System.currentTimeMills();
		return (now - start) / 1000.0;
	}
	
	public static void main(String[] args){
		int n = Integer.parseInt(args[0]);
		int[] a = new int[n];
		
		for (int i = 0; i < n; i++){
			a[i] = StdRandom.uniform(-1000000, 1000000);
		}
		Stopwatch timer = new Stopwatch();
		int cnt = ThreeSum.count(a);
		double time = timer.elapsedTime();
		StdOut.println(cnt + "triples" + time + "seconds");
	}
}