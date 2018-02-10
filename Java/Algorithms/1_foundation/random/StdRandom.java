/******************************************************************************
 *  Compilation:  javac StdRandom.java
 *  Execution:    java StdRandom
 *  Dependencies: StdOut.java
 *
 *  A library of static methods to generate pseudo-random numbers from
 *  different distributions (bernoulli, uniform, gaussian, discrete,
 *  and exponential). Also includes a method for shuffling an array.
 *
 *
 *  %  java StdRandom 5
 *  seed = 1316600602069
 *  59 16.81826  true 8.83954  0 
 *  32 91.32098  true 9.11026  0 
 *  35 10.11874  true 8.95396  3 
 *  92 32.88401  true 8.87089  0 
 *  72 92.55791  true 9.46241  0 
 *
 *  % java StdRandom 5
 *  seed = 1316600616575
 *  96 60.17070  true 8.72821  0 
 *  79 32.01607  true 8.58159  0 
 *  81 59.49065  true 9.10423  1 
 *  96 51.65818  true 9.02102  0 
 *  99 17.55771  true 8.99762  0 
 *
 *  % java StdRandom 5 1316600616575
 *  seed = 1316600616575
 *  96 60.17070  true 8.72821  0 
 *  79 32.01607  true 8.58159  0 
 *  81 59.49065  true 9.10423  1 
 *  96 51.65818  true 9.02102  0 
 *  99 17.55771  true 8.99762  0 
 *
 *
 *  Remark
 *  ------
 *    - Relies on randomness of nextDouble() method in java.util.Random
 *      to generate pseudorandom numbers in [0, 1).
 *
 *    - This library allows you to set and get the pseudorandom number seed.
 *
 *    - See http://www.honeylocust.com/RngPack/ for an industrial
 *      strength random number generator in Java.
 *
 ******************************************************************************/
 
import java.util.Random;
 
 /**
 *  The {@code StdRandom} class provides static methods for generating
 *  random number from various discrete and continuous distributions, 
 *  including Bernoulli, uniform, Gaussian, exponential, pareto,
 *  Poisson, and Cauchy. It also provides method for shuffling an
 *  array or subarray.
 *  <p>
 *  For additional documentation,
 *  see <a href="http://introcs.cs.princeton.edu/22library">Section 2.2</a> of
 *  <i>Introduction to Programming in Java: An Interdisciplinary Approach</i>
 *  by Robert Sedgewick and Kevin Wayne.
 *
 *  @author Robert Sedgewick
 *  @author Kevin Wayne
 */
public final class StdRandom{
	private static Random random;
	private static long seed;
	 
	// static initializer
	static{
		seed = System.currentTimeMillis();
		random = new Random(seed);	// [0,1)
	}
	 
	private StdRandom(){ }	// don't instantiate
	 
	public static void setSeed(long s){
		seed = s;
		randdom = new Random(seed);
	}
	
	public static long getSeed(){
		return seed;
	}
	 
	public static double uniform(){
		return random.nextDouble();
	}
	 
	public static int uniform(int n){
		if (n <= 0) throw new IllegalArgumentException("Parameter N must be positive");
		return random.nextInt(n);
	}
	 
	public static double random(){
		return uniform();
	}
	 
	public static int uniform(int a, int b){
		if (b <= a) throw new IllegalArgumentException("Invalid range");
		if ((long)b - a >= Integer.MAX_VALUE) throw new IllegalArgumentException("Invalid range");
		return a + uniform() * (b - a);
	}
	
	public static boolean bernoulli(double p){	// 伯努利
		if (!(p >= 0.0 && p <= 1.0){
			throw new IllegalArgumentException("Probability must be between 0.0 and 1.0");
		}
		return uniform() < p;
	}
	
	public static boolean bernoulli(){
		return bernoulli(0.5);
	}
	
	public static double gaussian(){
		double x;
		double y;
		double r;
		do{
			x = uniform(-1.0, 1.0);
			y = uniform(-1.0, 1.0);
			r = x * x + y * y;
		} while (r >= 1 || r == 0);
		
		return x * Math.sqrt(-2 * Math.log(r) / r);
	}
	
	public static double gaussian(double mu, double sigma){
		return mu + sigma * gaussian();
	}
	
	public static int geometric(double p){
		if (!(p >= 0.0 && p <= 1.0)){
			throw new IllegalArgumentException("Probability must be between 0.0 and 1.0");
		}
		return (int)Math.ceil(Math.log(uniform()) / Math.log(1.0 - p));
	}
	
	public static int poisson(double lambda){
		if (!(lambda > 0.0)){
			throw new IllegalArgumentException("Parameter lambda must be positive");
		}
		if (Double.isInfinite(lambda)){
			throw new IllegalArgumentException("Parameter lambda must not be infinite");
		}
		int k = 0;
		double p = 1.0;
		double L = Math.exp(-lambda);
		do{
			k++;
			p *= uniform();
		} while (p >= L);
		return k - 1;
	}
	
	public static double pareto(){
		return pareto(1.0);
	}
	
	/**
	* Returns a random real number from a Pareto distribution with
	* shape parameter &alpha;.
	*
	* @param  alpha shape parameter
	* @return a random real number from a Pareto distribution with shape
	*         parameter <tt>alpha</tt>
	* @throws IllegalArgumentException unless <tt>alpha > 0.0</tt>
	*/
	public static double pareto(double alpha){
		if (!(alpha > 0.0)){
			throw new IllegalArgumentException("Shape parameter alpha must be positive");
		}
		return Math.pow(1 - uniform(), -1.0 / alpha) - 1.0;
	}
	
	public static double cauchy(){
		return Math.tan(Math.PI * (uniform() - 0.5));
	}
	
	public static int discrete(double[] probabilities){
		if (probabilities == null){
			throw new NullPointerException("argument array is null");
		}
		double EPSILON = 1E-14;
		double sum = 0.0;
		for (int i = 0; i < probabilities.length; i++){
			if (!(probabilities[i] >= 0.0)){
				throw new IllegalArgumentException("array entry " + i + " must be nonnegative: " + probabilities[i]);
			}
			sum += probabilities[i];
		}
		if (sum > 1.0 + EPSILON || sum < 1.0 - EPSILON){
			throw new IllegalArgumentException("sum of array entries does not approximately equal 1.0: " + sum);
		}
		while (true){
			double r = uniform();
			sum = 0.0;
			for (int i = 0; i < probabilities.length; i++){
				sum = sum + probabilities[i];
				if (sum > r){
					return i;
				}
			}
		}
	}
	
	public static int discrete(int[] frequencies){
		if (frequencies == null){
			throw new NullPointerException("argument array is null");
		}
		long sum = 0;
		for (int i = 0; i < frequencies.length; i++){
			if (frequencies[i] < 0){
				throw new IllegalArgumentException("array entry " + i + " must be nonnegative: " + frequencies[i]);
			}
			sum += frequencies[i];
		}
		if (sum == 0){
			throw new IllegalArgumentException("at least one array entry must be positive");
		}
		if (sum >= Integer.MAX_VALUE){
			throw new IllegalArgumentException("sum of frequencies overflows an int");
		}
		
		double r = uniform((int)sum);
		sum = 0;
		for (int i = 0; i < frequencies.length; i++){
			sum += frequencies[i];
			if (sum > r){
				return i;
			}
		}
		assert false;	// can't reach here
		return -1;
	}
	
	public static double exp(double lambda){
		if (!(lambda > 0.0)){
			throw new IllegalArgumentException("Rate lambda must be positive");
		}
		return -Math.log(1- uniform()) / lambda;
	}
	
	public static void shuffle(Object[] a){
		if (a == null){
			throw new NullPointerException("argument array is null");
		}
		int n = a.length;
		for (int i = 0; i < n; i++){
			int r = i + uniform(n - i);
			Object temp = a[i];
			a[i] = a[r];
			a[r] = tempp;
		}
	}
	
	public static void shuffle(double[] a){
		if (a = null){
			throw new NullPointerException("argument array is null");
		}
		int n = a.length;
		for (int i = 0; i < n; i++){
			int r = i + uniform(n - i);
			double temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
	}
	
	public static void shuffle(int[] a){
		if (a == null){
			throw new NullPointerException("argument array is null");
		}
		int n = a.length;
		for (int i = 0; i < n; i++){
			int r = i + uniform(n - i);
			int temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
	}
	
	public static void shuffle(Object[] a, int lo, int hi){
		if (a == null){
			throw new NullPointerException("argument array is null");
		}
		if (lo < 0 || lo > hi || hi >= a.length){
			throw new IndexOutOfBoundsException("Illegal subarray range");
		}
		for (int i = lo; i <= hi; i++){
			int r = i + uniform(hi - i + 1);
			Object temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
	}
	
	public static void shuffle(double[] a, int lo, int hi){
		if (a == null){
			throw new NullPointerException("argument array is null");
		}
		if (lo < 0 || lo > hi || hi >= a.length){
			throw new IndexOutOfBoundsException("Illegal subarray range");
		}
		for (int i = lo; i <= hi; i++){
			int r = i + uniform(hi - i + 1);
			double temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
	}
	
	public static void shuffle(int[] a, int lo, int hi){
		if (a == null){
			throw new NullPointerException("argument array is null");
		}
		if (lo < 0 || lo > hi || hi >= a.length){
			throw new IndexOutOfBoundsException("Illegal subarray range");
		}
		for (int i = lo; i <= hi; i++){
			int r = i + uniform(hi - i + 1);
			int temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
	}
	
	/**
	*	Unit test
	*/
	public static void main(String[] args){
		int n = Integer.parseInt(args[0]);
		if (args.length == 2){
			StdRandom.setSeed(Long.parseLong(args[1]));
		}
		double[] probabilities = { 0.5, 0.3, 0.1, 0.1 };
		int[] frequencies = { 5, 3, 1, 1 };
		String[] a = "A B C D E F G".split(" ");
		
		StdOut.println("seed = " + StdRandom.getSeed());
		for (int i = 0; i < n; i++){
			StdOut.printf("%2d ", uniform(100));
			StdOut.printf("%8.5f ", uniform(10.0, 99.0));
			StdOut.printf("%5b ", bernoulli(0.5));
			StdOut.printf("%7.5f ", gaussian(9.0, 0.2));
			StdOut.printf("%1d ", discrete(probabilities));
			StdOut.printf("%1d ", discrete(frequencies));
			StdRandom.shuffle(a);
			for (String s : a){
				StdOut.print(s);
			}
			StdOut.println();
		}
	}
}