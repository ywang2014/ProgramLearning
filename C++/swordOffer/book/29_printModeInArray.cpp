/**
	数组中出现次数超过一半的数字
	
	数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	
	例如：输入长度为9的数组：{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中出现了5次，超过了数组长度的一半，因此输出2.
*/

// 版本一：直接扫描查找，时间复杂度：O(n^2)
void printModeNumber(int* data, unsigned int n)
{
	if (data == NULL || n == 0)
	{
		return ;
	}
	
	unsigned int halfLength = n >> 1;
	
	for (unsigned int index = 0; index < n; index++)
	{
		unsigned int count = 0;
		for (unsigned int it = 0; it < n; it++)
		{
			if (data[index] == data[it])
			{
				count++;
			}
		}
		
		if (halfLength < count)
		{
			printf("%d\n", data[index]);
			break;
		}
	}
}

// 版本二：哈希表方法，使用计数排序，时间复杂度：O(n)，空间复杂度：O(K) k = maxValue - minValue
void printModeNumber(int* data, unsigned int n)
{
	if (data == NULL || n == 0)
	{
		return ;
	}
	
	// 寻找数组中的最大值和最小值
	int maxValue = data[0];
	int minValue = data[0];
	for (unsigned int index = 1; index < n; index++)
	{
		if (maxValue < data[index])
		{
			maxValue = data[index];
		}
		
		if (minValue > data[index])
		{
			minValue = data[index];
		}
	}
	
	// 统计各元素出现的频率
	unsigned int countLength = maxValue - minValue + 1;
	int* count = new int[countLength];
	for (unsigned int index = 0; index < n; index++)
	{
		count[ data[index] - minValue ] ++;
	}
	
	for (unsigned int index = 0; index < countLength; index++)
	{
		if (count[index] > halfLength)
		{
			print("%d\n", index + minValue);
			break;
		}
	}
}

// 版本三：时间复杂度：O(n)		空间复杂度：O(1)
void printModeNumber(int* data, unsigned int n)
{
	int currentValue = data[0];
	unsigned int count = 0;
	
	for (unsigned int index = 0; index < n; index++)
	{
		if (count == 0)
		{
			currentValue = data[index];
			count++;
		}
		else 
		{
			if ( currentValue == data[index] )
			{
				count++;
			}
			else 
			{
				count--;
			}
		}
	}
	
	printf("%d\n", currentValue);
}

/******************************************** 参考代码  **/
// 如果数组有序，则该众数，一定是中位数。
// 基于快速排序算法的实现
int moreThanHalfNum(int* numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
	{
		return 0;
	}
	
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else 
		{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}
	
	int result = numbers[middle];
	
	if (!CheckMoreThanHalf(numbers, length, result))
	{
		return 0;
	}
	
	return result;
}

int Partition(int* data, int n, int start, int end)
{
	if (data == NULL || n < 1 || start < 0 || n <= end)
	{
		return 0;	// invalid arguments
	}
	
	int pivot = data[end];
	
	while (start < end)
	{
		while (start < end && data[start] < pivot)
		{
			start++;
		}
		
		if (start < end) 
		{
			data[end--] = data[start];
		}
		
		while (start < end && pivot < data[end])
		{
			end--;
		}
		
		if (start < end)
		{
			data[start++] = data[end];
		}	
	}
	
	return start;
}

// 错误参数检查
bool g_invalidInput = false;

bool checkInvalidArray(int* numbers, int length)
{
	g_invalidInput = false;
	
	if (numbers == NULL && length <= 0)
	{
		g_invalidInput = true;
	}
	
	return g_invalidInput;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number) 
		{
			times++;
		}
	}
	
	bool isMoreThanHalf = true;
	if (times * 2 <= length)
	{
		g_invalidInput = true;
		isMoreThanHalf = false;
	}
	
	return isMoreThanHalf;
}