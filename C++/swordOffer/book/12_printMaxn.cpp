/**
	打印1到最大的n位数
	
	输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数，即999.
*/
int printMaxn(int n)
{
	if (n <= 0)		// 如果输入参数非法，则打印0
	{
		return 0;
	}
	else if (n > 9)
	{
		// 特殊处理，太大
	}
	
	int maxNum = 1;
	while (n > 0)
	{
		maxNum *= 10;
		n--;
	}
	
	for (int i = 1; i < maxNum; i++)
	{
		printf("%d\n", i);
	}
	
	return 0;
}

// 处理大数版本，字符串存储
int printMaxN(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	
	string maxNum(n, ' ');	// 初始化为 0
	maxNum[n] = '1';	// 第一个打印的是 1
	while (maxNum[0] != '9')
	{
		cout << maxNum << endl;
		maxNum = add1(maxNum);
	}
	
	cout << maxNum << endl;
	
	return 0;
}

string add1(string s)
{
	int index = s.size();
	while (index && s[index] == '9')
	{
		s[index] = '0';
		index--;
	}
	if (s[index] == ' ')	// 空格，实际就是代表 0
	{
		s[index] = '1';
	}
	else 
	{
		s[index]++;	// 字符加1
	}
	
	return s;
}


// 参考答案
void print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
	{
		return ;
	}
	
	char *number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	
	while (!Increment(number))
	{
		printNumber(number);
	}
	
	delete [] number;
}

bool Incerment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
		{
			nSum++;
		}
		
		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	
	return isOverflow;
}

void printNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	
	for (int i = 0; i < nLength; i++)
	{
		if (isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
		}
		
		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}
	
	printf("\t");
}