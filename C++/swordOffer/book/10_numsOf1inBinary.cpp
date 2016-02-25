/**
	二进制中1的个数
	
	请实现一个函数，输入一个整数，输出该数的二进制表示中1的个数。
	例如：把9表示成二进制是1001，有2位是1。因此输入9，则输出2
	
*/
int numsOf1(int n)
{
	int sum = 0;
	
	if (n < 0)
	{
		n = 2 << 31 + n;
	}
	
	while (n > 0)
	{
		if (n & 1)
		{
			sum++;
		}
		n = n >> 1;
	}
	
	return sum;
}

// 参考答案 	解决负数问题，左移判断
int numsOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}
		
		flag = flag << 1;
	}
	
	return count;
}

// 更加高效的算法
int numsOf1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n - 1);
	}
	
	return count;
}