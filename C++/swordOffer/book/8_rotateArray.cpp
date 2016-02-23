/**
	旋转数组的最小数字
	
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出一个旋转数组的最小元素。
	例如：数组{3,4,5,1,2}为数组{1,2,3,4,5,}的一个旋转，该数组的最小值为1.
	
	有序数组旋转之后，就是两个有序数组！
	
	“搬到末尾” : 因此不存在 lo < mid < hi 的模式，一定是 lo>=hi
*/

// 没有处理，完全有序的特例情况
int minRotateArray(int* arr, int n)
{
	if (arr == NULL || n < 1)
	{
		return -1;	// 输入非法情况
	}
	else if (n == 1)
	{
		return arr[0];
	}
	
	int lo = 0;
	int hi = n - 1;
	
	while (lo < hi - 1)
	{
		
		int mid = (lo + hi) >> 1;
		
		if (arr[mid] < arr[hi])
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	
	return arr[hi];
}

/************************* 参考答案 *****************/
int min(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		throw new std::exception("Invalid parameters.");
	}
	
	int index_lo = 0;
	int index_hi = length - 1;
	int index_mid = index_lo;
	while (numbers[index_lo] >= numbers[index_hi])
	{
		if (index2 - index1 == 1)
		{
			index_mid = index_hi;
			break;
		}
		
		index_mid = (index_lo + index_hi) / 2;
		if (numbers[index_lo] <= numbers[index_mid])
		{
			index_lo = idnex_mid;
		}
		else if (numbers[index_mid] <= numbers[index_hi])
		{
			index_hi = index_mid;
		}
	}
	return numbers[index_mid];
}

/***************************************** 修改、完善版本  *****************************/
int minRotateArray(int* nums, int length)
{
	if (nums == NULL || length <= 0)
	{
		throw std::exception("Invalid parameters");
	}
	
	int index_lo = 0;
	int index_hi = length - 1;
	int index_mid = index_lo;
	while (nums[index_lo] >= nums[index_hi])
	{
		if (index_hi - index_lo == 1)
		{
			index_mid = index_hi;
			break;
		}
		
		index_mid = (index_lo + idnex_hi) / 2;
		
		// 当三个数相等时，必须顺序搜索
		if (nums[index_lo] == nums[index_hi] && nums[index_lo] == nums[index_mid])
		{
			return minInorder(numbers, index_lo, index_hi);
		}
		
		if (nums[index_lo] <= nums[index_mid])
		{
			index_lo = index_mid;
		}
		else if (nums[index_mid] <= nums[index_hi])
		{
			index_hi = index_mid;
		}
	}
	return nums[index_mid];
}

int minInorder(int* nums, int lo, int hi)
{
	int minNum = nums[lo];
	for (int i = lo; i <= hi; i++)
	{
		if (nums[i] < minNum)
		{
			// swap(minNum, nums[i]);
			minNum = nums[i];
		}
	}
	
	return minNum;
}