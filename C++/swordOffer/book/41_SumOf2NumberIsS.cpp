/**
	和为s的两个数字VS和为s的连续正数序列
	
	输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
	
	如果有很多对数字的和等于s，输出任意一对即可。
*/

void print2Number(int* data, unsigned int n, int sum)
{
	int firstNumber = 0;
	int secondNumberIndex = 0
	
	for (unsigned int index = 0; index < length; index++)
	{
		firstNumber = data[index];
		
		// 使用二分查找法
		secondNumberIndex = binarySearch(data, 0, n, sum - firstNumber);
		
		if (secondNumberIndex != index && 
			secondNumberIndex != n &&
			(firstNumber + data[secondNumberIndex] == sum) )
		{
			printf("%d %d\n", firstNumber, sum - firstNumber);
			break;
		}
	}
	
	
}


/************************************** 参考代码 *******/
bool findNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	
	if (data == NULL || length < 1 || num1 == NULL || num2 == NULL)
	{
		return found;
	}
	
	int first = 0;
	int last = length - 1;
	
	while (first < last)
	{
		long long currentSum = data[first] + data[last];
		
		if (currentSum == sum)
		{
			*num1 = data[first];
			*num2 = data[last];
			found = true;
			break;
		}
		else if (currentSum < sum)
		{
			first++;
		}
		else
		{
			last--;
		}
	}
	
	return found;
}