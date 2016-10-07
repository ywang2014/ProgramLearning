/**
	two sum 
*/
import java.util.Arrays;

public class TwoSumFast{
	public static int count(int[] a){
		Arrays.sort(a);
		int n = a.length;
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (BinarySearch.rank(-a[i], a) > i){
				cnt++;
			}
		}
		
		return cnt;
	}
	
	public static void main(String[] args){
		int[] a = In.readInts(args[0]);
		StdOut.println(count(a));
	}
}