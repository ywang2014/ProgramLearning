/**
	数字在排序数组中出现的次数
	
	统计一个数字在排序数组中出现的次数。
	
	例如：输入排序数组{1, 2, 3, 3, 3, 3, 4, 5}和数字3, 3在数组中出现了4次，因此输出4.
*/

int timesOfNumber(int* data, unsigned int length, int number)
{
	if (data == NULL || length == 0)
	{
		return 0;	// invalid parameters
	}
	
	int indexFirst = binarySearchStart(data, 0, length, number);
	int indexLast = binarySearchEnd(data, 0, length, number);
	
	return indexLast - indexFirst + 1;
}


// 二分查找，返回找到的元素的首次出现的位置
int binarySearchStart(int* data, unsigned int start, unsigned int end, int keyValue)
{
	if (start == NULL || start >= end)
	{
		return 0;	// invalid parameter 
	}
	
	while (start < end)
	{
		int mid = (start + end) >> 1;
		
		if (data[mid] < keyValue)
		{
			start = mid + 1;
		}
		else 
		{
			end = mid;
		}
	}
	
	return start;
}


// 二分查找，返回找到的元素的最后一次出现的位置
int binarySearchEnd(int* data, unsigned int start, unsigned int end, int keyValue)
{
	if (start == NULL || start >= end)
	{
		return 0;	// invalid parameter 
	}
	
	while (start < end)
	{
		int mid = (start + end) >> 1;
		
		if (data[mid] > keyValue)
		{
			end = mid;
		}
		else 
		{
			start = mid + 1;
		}
	}
	
	return end - 1;
}



/********************** 参考代码		******/
int getFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	
	int middleIndex = (start + end) / 2;
	int currentData = data[middleIndex];
	
	if (currentData == k)
	{
		if (middleIndex == 0 || (middleIndex > 0 && data[middleIndex - 1] != k) )
		{
			return middleIndex;
		}
		else
		{
			end = middleIndex - 1;
		}
	}
	else if (currentData > k) 
	{
		end = middleIndex - 1;
	}
	else 
	{
		start = middleIndex + 1;
	}
	
	return getFirstK(data, length, k, start, end);
}


int getLastK(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	
	int middleIndex = (start + end) / 2;
	int currentData = data[middleIndex];
	
	if (middleIndex == k)
	{
		if (middleIndex == end || (middleIndex < end && data[middleIndex + 1] != k) )
		{
			return middleIndex;
		}
		else
		{
			start = middleIndex + 1;
		}
	}
	else if (currentData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}
	
	return getLastK(data, length, k, start, end);
}


int getNumbersOfK(int* data, int length, int k)
{
	int number = 0;
	
	if (data != NULL && length > 0)
	{
		int first = getFirstK(data, length, k, 0, length - 1);
		int last = getLastK(data, length, k, 0, length - 1);
		
		if (first > -1 && last > -1)
		{
			number = last - first + 1;
		}
	}
	
	return number;
}