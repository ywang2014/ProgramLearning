/**
	binary search
*/
import java.util.Arrays;

public class BinarySearch{
	public static int rank(int key, int[] a){
		int lo = 0;
		int hi = a.length - 1;
		while (lo <= hi){
			int mid = (hi - lo) / 2;
			if (key < a[mid]){
				hi = mid - 1;
			}
			else if (key == a[mid]){
				return mid;
			}
			else{
				lo = mid + 1;
			}
		}
		
		return -1;
	}
	
	public static void main(String[] args){
		int[] whitelist = StdIn.readInts(args[0]);
		
		Arrays.sort(whitelist);
		
		while (!StdIn.isEmpty()){
			int key = StdIn.readInt();
			if (rank(key, whitelist) == -1){
				StdOut.println(key);
			}
		}
	}
}

class StdIn{
	public static double[] readDoubles(String path){
		List<String> list = new ArrayList<String>();
		
		try{
			String encoding = "utf-8";
			File file = new File(path);
			
			if (file.isFile() && file.exists()){
				InputStreamReader read = new InputStreamReader(
					new FileInputStream(file), encoding
				);
				BufferedReader br = new BufferedReader(read);
				String line = null;
				while ((line = br.readLine()) != null){
					list.add(line);
				}
				br.close();
			}
		}
		catch (IOException e){
			e.printStackTrace();
		}
		
		double[] nums = new double[list.size()];
		for (int i = 0; i < list.size(); i++){
			String s = (String)list.get(i);
			nums[i] = Double.parseDouble(s);
		}
		
		return nums;
	}
	
	public static int[] readInts(String path){
		List<int> list = ArrayList<int>();
		try{
			FileInputStream fin = new FileInputStream(path);
			DataInputStream din = new DataInputStream(fin);
			int data;
			
			while ((data = din.readInt()) != null){
				list.add(data);
			}
			din.close();
		}
		catch (IOException e){
			e.printStackTrace();
		}
		
		int[] nums = new int[list.size()];
		for (int i = 0; i < list.size(); i++){
			nums[i] = (int)list.get(i);
		}
		
		return nums;
	}
	
	public static int readInt(){
		try{
			Scanner input = new Scanner(System.in);
		
			return input.nextInt();
		}
		catch (IOException e){
			e.printStackTrace();
		}
	}
}