/**
	把数组排成最小的数
	
	输入一个正整数数组，把数组里所有数字拼接起来，排成一个数，打印能拼接出的所有数字中最小的一个。
	
	例如：输入数组{3, 32, 321}
		打印出三个数字可以排列的最小数字 321323
*/

void printMinNumberOfPermutation(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return ;
	}
	
	sort(data, data+length, cmp_less);
	
	// 不考虑溢出问题
	int number = data[0];
	for (unsigned int index = 1; index < length; index++)
	{
		number = splice2number(number, data[index]);
	}
	
	printf("%d\n", number);
}

// 根据两个数字排列的大小，重新定义小于号
bool cmp_less(const int a, const int b)
{
	if (a == 0)
	{
		return false;
	}
	else if (b == 0)
	{
		return true;
	}
	
	int ab = splice2number(a, b);
	int ba = splice2number(b, a);
	
	retrun ab < ba;
}


// 计算一个整数的位数
int bitsOfNumber(unsigned int n)
{
	if (n == 0)
	{
		return 1;
	}
	
	int count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	
	return count;
}


// 10的整数次幂
int powerBase10(unsigned int n)
{
	int result = 1;
	
	while (n > 0)
	{
		result *= 10;
		n--;
	}
	
	return result;
}


// 拼接两个整数
int splice2number(const int higher, const int lower) 
{
	if (higher == 0)
	{
		return lower;
	}
	else if (lower == 0)
	{
		return higher;
	}
	
	return higher * powerBase10( bitsOfNumber(lower) ) + lower;
}