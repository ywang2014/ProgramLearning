/**
 * 闪银一面算法题：
 * 	1.求出连续的子数组最大和
 * 	2.输出最大子数组的起点和终点
 * 
 * @author Administrator
 *
 */
public class MaxSubArray {
	public static void main(String[] args){
		MaxSubArray solution = new MaxSubArray();
		System.out.println(solution.find(solution.mockArray()).sum);
		
	}
	
	private class SubArray{
		private long sum;	// the sum of subarray
		private int low;	// start point
		private int high;	// end point, high is not the index in array!
		
		public SubArray(long sum, int low, int high) {
			this.sum = sum;
			this.low = low;
			this.high = high;
		}
	}
	
	public SubArray find(int[] array){
		if (array == null || array.length == 0){
			return new SubArray(-1, 0, 0);
		}
		int len = array.length;
		int currentSum = 0;
		SubArray maxSubArray = new SubArray(0, 0, 0);
		int l = 0;
		int r = 0;
		for (int i = 0; i < len; i++){
			currentSum += array[i];
			r = i + 1;
			if (maxSubArray.sum < currentSum){
				maxSubArray.sum = currentSum;
				maxSubArray.low = l;
				maxSubArray.high = r;
			}
			if (currentSum < 0){
				currentSum = 0;
				l = i+1;
				r = i+1;
			}
		}
		return maxSubArray;
	}
	
	public int[] mockArray(){
		int[] array = new int[8];
		array[0] = -1;
		array[1] = -3;
		array[2] = 3;
		array[3] = 2;
		array[4] = -1;
		array[5] = 4;
		array[6] = -10;
		array[7] = 2;
 		return array;
	}

}
