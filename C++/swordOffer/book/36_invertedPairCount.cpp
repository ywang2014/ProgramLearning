/**
	数组中的逆序对
	
	在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
	输入一个数组，求出这个数组中的逆序对的总数。
*/

int inversePairCount(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return 0;
	}
	
	int *data_copy = new int[length];
	for (unsigned int index = 0; index < length; index++)
	{
		data_copy[index] = data[index];
	}
	
	int pairCount = inversePairCountRecursive(data_copy, 0, length);
	
	delete[] data_copy;
	
	return pairCount;
}

// [lo, hi)半开区间
int inversePairCountRecursive(int* data, int lo, int hi)
{
	if (lo >= hi - 1)
	{
		return 0;
	}
	
	int mid = (lo + hi) >> 1;
		
	int leftCount = inversePairCountRecursive(data, lo, mid);
	int rightCount = inversePairCountRecursive(data, mid, hi);
	
	int mergeCount = inversePairCountMerge(data, lo, mid, hi);
	
	return leftCount + rightCount + mergeCount;

}

// [lo, hi)半开区间
int inversePairCountMerge(int* data, int lo, int mid, int hi)
{
	int l_len = mid - lo;
	int r_len = hi - mid;
	
	int* l_data = new int[l_len];
	int* r_data = new int[r_len];
	
	for (unsigned int index = 0; index < l_len; index++)
	{
		l_data[index] = data[lo + index];
	}
	
	for (unsigned int index = 0; index < r_len; index++)
	{
		r_data[index] = data[mid + index];
	}
	
	int inversePairCount = 0;
	
	int l_index = 0;
	int r_index = 0;
	unsigned int index = lo; 
	
	while (index < hi)
	{
		// 此处必须有一个地方有等于号，否则遇到相同数字，无法处理
		while (l_index < l_len && (r_index == r_len || l_data[l_index] <= r_data[r_index]))
		{
			data[index++] = l_data[l_index++];
		}
		
		while (r_index < r_len && (l_index == l_len || r_data[r_index] < l_data[l_index]))
		{
			inversePairCount += (l_len - l_index);
			
			data[index++] = r_data[r_index++];
		}
	}
}



/******************************* 参考代码 *****/
// 基于分治思想方法---类似于归并排序
int inversePairs(int* data, int length)
{
	if (data == NULL || length < 1)
	{
		return 0;
	}
	
	int* copy = new int[length];
	for (int index = 0; index < length; index++)
	{
		copy[i] = data[i];
	}
	
	int count = inversePairsCore(data, copy, 0, length);
	
	delete[] copy;
	
	return count;
}

int inversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	
	int halfLength = (end - start) >> 1;
	
	int left = inversePairsCore(data. copy, start, start + halfLength);
	int right = inversePairsCore(data, copy, start+halfLength+1, end);
	
	int i = start + halfLength;
	int j = end;
	
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + halfLength + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else 
		{
			copy[indexCopy--] = data[j--];
		}
	}
	
	for (; i >= start; i--)
	{
		copy[indexCopy--] = data[i];
	}
	
	for (; j >= start + halfLength + 1; j--)
	{
		copy[indexCopy--] = data[j];
	}
	
	return left + right + count;
}