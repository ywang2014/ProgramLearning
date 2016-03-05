/**
	递归版本的12题
	打印1到n位的最大数字
*/
void print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
	{
		return ;
	}
	
	char *num = new char[n+1];
	num[n] = '\0';
	
	for (int i = 0; i < 10; i++)	// 起始位也有10种情况
	{
		num[0] = i + '0';	// 0 - 9
		print1ToMaxNRecursively(num, n, 0);
	}
	
	delete[] num;
}

void print1ToMaxNRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		printNumber(number);
		return ;
	}
	
	for (int i = 0; i < 10; i++)	// 每一位可以设置为 0-9	10种情况
	{
		number[index + 1] = i + '0';	// 0-9
		print1ToMaxNRecursively(number, length, index+1);
	}
}