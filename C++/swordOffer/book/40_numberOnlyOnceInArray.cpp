/**
	数组中只出现一次的数字
	
	一个整形数组里除了两个数字之外，其他数字都出现了两次。
	请写程序找出这个两个只出现一次的数字。
	
	要求：时间复杂度O(n)，空间复杂度O(!)
*/

void findTheNumberOnlyOnce(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return ;
	}
	
	int firstNumber = 0;
	int secondNumber = 0;
	
	void findNumber(data, length, firstNumber, secondNumber);
	
	printf("%d\t%d\n", firstNumber, secondNumber);
}

void findNumber(int* data, unsigned int length, int& firstNumber, int& secondNumber)
{
	if (data == NULL || length == 0 || firstNumber == NULL || secondNumber == NULL)
	{
		return ;
	}
	
	int resultOR = 0;
	for (unsigned int index = 0; index < length; index++)
	{
		resultOR ^= data[index];
	}
	
	// 找出第一个非0位
	unsigned int firstBitOne = 1;
	while (firstBitOne & resultOR == 0)
	{
		firstBitOne <<= 1;
	}
	
	firstNumber = 0;
	secondNumber = 0;
	// 按照bitZero位分组。
	for (unsigned int index = 0; index < length; index++)
	{
		if (firstBitOne & data[index] == 1) 
		{
			firstNumber ^= data[index];
		}
		else
		{
			secondNumber ^= data[index];
		}
	}
}