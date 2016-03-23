/**
	从1到n整数中1出现的次数
	
	输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。
	
	例如：输入12，从1到12这些整数中包含1的数字有1,10,11和12，1一共出现了5次。
*/

// 直接法，时间复杂度：n*bits(n)
int countsOf1(int n)
{
	if (n < 1)
	{
		return 0;
	}
	
	int count = 0;
	for (int index = 1; index <= n; index++)
	{
		int currentNumber = index;
		while (currentNumber > 0)
		{
			if (currentNumber % 10 == 1)
			{
				count++;
			}
			
			currentNumber /= 10;
		}
	}
	
	return count;
}


// sprintf() 把格式化的数据写入某个字符串中
// sscanf()  从一个字符串中读进与指定格式相符的数据

int numberOf1Between1Andn(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	
	// 把数字转换为字符串
	char strN[50];
	sprintf(strN, "%d", n);
	
	return numberOf1(strN);
}

int numberOf1(const char* str)
{
	if (str == NULL || *str < '0' || *str > '9' || *str == '\0')
	{
		return 0;
	}
	
	int first = *str - '0';
	unsigned int length = static_cast<unsigned int>(strlen(str));
	
	if (length == 1 && first == 0)
	{
		return 0;
	}
	else if (length == 1 && first > 0)
	{
		return 1;
	}
	
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = PowerBase10(length - 1);
	}
	else if (first == 1)
	{
		numFirstDigit = atoi(str+1) + 1;	// str+1即指针指向的数字位置右移一位！
	}
	
	int numOtherDigits = first * (length - 1) * powerBase10(length - 2);
	
	// 递归调用
	int numRecursive = numberOf1(str + 1);
	
	return numFirstDigit + numOtherDigits + numRecursive;
}

int powerBase10(unsigned int n)
{
	int result = 1;
	while (n--)
	{
		result *= 10;
	}
	
	return result;
}