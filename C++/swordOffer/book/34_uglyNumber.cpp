/**
	丑数
	
	我们把只包含因子2、3、5的数称作丑数。求按从小到大的顺序的第1500个丑数。
	
	例如：6 8都是丑数，但14不是，因为14包含因子7.
	
	习惯上，把1当做第一个丑数。
*/

// 直接方法，顺序检查每一个数，直到数到第k个丑数
int KthUglyNumber(unsigned int k)
{
	if (k == 0)
	{
		return 0;
	}
	
	unsigned int uglyNums = 0;
	unsigned int currentNum = 1; 
	
	while (uglyNums < k)
	{
		if (isUglyNumber(currentNum))
		{
			uglyNums++;
		}
		
		currentNum++;
	}
	
	return currentNum;
}


// 判断某整数是否是丑数
bool isUglyNumber(unsigned int number)
{
	// 1是第一个丑数
	// if (number == 1)
	// {
		// return false;
	// }
	
	while (number != 1)
	{
		if (number % 2 == 0)
		{
			number /= 2;
		}
		else if (number % 3 == 0)
		{
			number /= 3;
		}
		else if (number % 5 == 0)
		{
			number /= 5;
		}
		else 
		{
			return false;
		}
	}
	
	return true;
}


/************************** 参考代码 **/
bool isUgly(int number)
{
	// 添加代码----参数异常处理
	if (number < 1)
	{
		return false;
	}
	// 添加代码 end
	
	while (number % 2 == 0)
	{
		number /= 2;
	}
	
	while (number % 3 == 0)
	{
		number /= 3;
	}
	
	while (number % 5 == 0)
	{
		number /= 5;
	}
	
	return number == 1;
}


// 版本二：空间换时间的高效率解法
int getUglyNumber(unsigned int number)
{
	if (number == 0)
	{
		return 0;
	}
	
	int *uglyNumbers = new int[number];
	uglyNumbers[0] = 1;
	
	int uglyNumberCount = 1;
	
	int* multiply2 = uglyNumbers;
	int* multiply3 = uglyNumbers;
	int* multiply5 = uglyNumbers;
	
	while (uglyNumberCount	< number)
	{
		int minNumber = minUglyNumber(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
		uglyNumbers[uglyNumberCount++] = minNumber;
		
		// while可以使用if替代 ！！！！
		while (*multiply2 * 2 <= minNumber)
		{
			multiply2++;
		}
		
		while (*multiply3 * 3 <= minNumber)
		{
			multiply3++;
		}
		
		while (*multiply5 * 5 <= minNumber)
		{
			multiply5++;
		}
	}
	
	int uglyNumberResult = uglyNumbers[uglyNumberCount - 1];
	delete[] uglyNumbers;
	
	return uglyNumberResult;
}


// 返回三个数最小值
int minUglyNumber(const int a, const int b, const int c)
{
	int minNumber = (a < b) ? a : b;
	return (minNumber < c) ? minNumber : c;
}