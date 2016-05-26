/**
	Three sum 
	sort first
	binary search
*/
import java.util.Arrays;

public class ThreeSumFast{
	public static int count(int[] a){
		Arrays.sort(a);
		int n = a.length;
		int cnt = 0;
		
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (BinarySearch.rank(-a[i]-a[j], a) > j){
					cnt++;
				}
			}
		}
		
		return cnt;
	}
	
	public static void main(String[] args){
		int[] a = In.readInts(args[0]);
		StdOut.println(count(a));
	}
}