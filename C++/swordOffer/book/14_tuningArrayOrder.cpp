/**
	调整数组顺序使得奇数位于偶数前面
	
	输入一个整数数组，实现一个函数来调整该数组中的数字顺序，使得所有奇数位于数组前半部分，所有的偶数位于数组后半部分。
*/

void tuningArray(int* originArray, int n)
{
	int tempArray[n] = { 0 };
	for (int i = 0; i < n; i++)
	{
		tempArray[i] = originArray[i];
	}
	
	int frontIndex = 0;		// 前端索引
	int backIndex = n;		// 后端索引
	for (int i = 0; i < n; i++)
	{
		if (tempArray[i] & 1 == 1)
		{
			originArray[frontIndex++] = tempArray[i];
		}
		else
		{
			originArray[--backIndex] = tempArray[i];
		}
	}
}

// 参考代码
// 1.直接遍历，遇见偶数，直接向后移动，逆向插入法一样	时间复杂度：O(n^2)，空间复杂度：O(1)

// 2.两个指针定位，直接交换奇偶数。时间复杂度：O(n)，空间复杂度：O(1)
void ReorderOddEven(int* pData, unsigned int length)
{
	if (pData == NULL || length == 0)
	{
		return ;
	}
	
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	
	while (pBegin < pEnd)
	{
		// 向后移动pBegin，直到遇到偶数
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
		{
			pBegin++;
		}
		
		// 向前移动pEnd，直到遇到奇数
		while (pBegin < pEnd && (*pEnd & 0x01) != 1)
		{
			pEnd--;
		}
		
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

/**
	函数指针参数的模板形式
	
	函数指针，专门提供判断标准，利于扩展
	
*/
void reorder(int *pData, unsigned int length, bool (*func) (int))
{
	if (pData == NULL || length == 0 || func == NULL)
	{
		return ;
	}
	
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && func(*pBegin))
		{
			pBegin++;
		}
		
		while (pBegin < pEnd && ! func(*pEnd))
		{
			pEnd--;
		}
		
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBbegin  = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isNegative(int value)
{
	if (value < 0)	// 满足某个条件即可
	{
		return true;
	}
	
	return false;
}

void ReorderNegative(int *pData, int length)
{
	reorder(pData, length, isNegative);
}