/**
	连续子数组的最大和
	
	输入一个整型数组，数组里有整数，也有负数。数组中一个或连续的多个整数组成一个子数组。求所有子数组的和的最大值。
	要求时间复杂度为O(n).
*/
// 方法一：最直接，简单的方法，时间复杂度：O(n^3)
int maxSumOfArray(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return ;
	}
	
	int maxSum = data[0];
	
	for (unsigned int startIndex = 0; startIndex < length; startIndex++)
	{
		for (unsigned int endIndex = startIndex; endIndex < length; endIndex++)
		{
			int currentSum = 0;
			for (unsigned int sumIndex = startIndex; sumIndex <= endIndex; sumIndex++)
			{
				currentSum += data[sumIndex];
			}
			
			if (maxSum < currentSum)
			{
				maxSum = currentSum;
			}
		}
	}
	
	return maxSum;
}


// 方法二：直接，简单的方法，时间复杂度：O(n^2)
int maxSumOfArray(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return ;
	}
	
	int maxSumResult = data[0];
	for (unsigned int index = 0; index < length; index++)
	{
		int maxSum = data[index];
		int sum = 0;
		for (unsigned int sumIndex = index; sumIndex < length; sumIndex++)
		{
			sum += data[sumIndex];
			
			// 每次求和，即完成一次序列的求和，所以比较一次，重复利用前一次的求和，叠加，所以复杂度减低一个量级！
			if (maxSum < sum)
			{
				maxSum = sum;
			}
		}
		
		if (maxSumResult < maxSum)
		{
			maxSumResult = maxSum;
		}
	}
}


// 版本三：基于分治的递归解法，时间复杂度：O(n*log(n))
int maxSumOfArray(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return 0;
	}	
	
	return maxSubSum(data, 0, length - 1);
}

int maxSubSum(int* data, unsigned int lo, unsigned int hi)
{
	if (lo == hi)
	{
		return data[lo];
	}
	
	unsigned int mid = (lo + hi) >> 1;
	int leftMaxSum = maxSubSum(data, lo, mid);
	int rightMaxSum = maxSubSum(data, mid+1, hi);
	
	int leftBoardSum = 0;
	int maxLeftBoardSum = 0;
	for (unsigned int index = center; index >= left; index--)
	{
		leftBoardSum += data[index];
		
		if (maxLeftBoardSum < leftBoardSum)
		{
			maxLeftBoardSum = leftBoardSum;
		}
	}
	
	int rightBoardSum = 0;
	int maxRightBoardSum = 0;
	for (unsigned int index = center; index <= hi; index++)
	{
		rightBoardSum += data[index];
		
		if (maxRightBoardSum < rightBoardSum)
		{
			maxRightBoardSum = rightBoardSum;
		}
	}
	
	return maxValue(leftMaxSum, rightMaxSum, maxLeftBoardSum + maxRightBoardSum);
}


// 版本四：基于动态规划的解法，时间复杂度：O(n)
int maxSumOfArray(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return 0;
	}
	
	int maxSum = data[0];
	int currentMax = data[0];
	for (unsigned int index = 1; index < length; index++)
	{
		currentMax = max(currentMax + data[index], data[index]);
		
		if (maxSum < currentMax)
		{
			maxSum = currentMax;
		}
	}
}
