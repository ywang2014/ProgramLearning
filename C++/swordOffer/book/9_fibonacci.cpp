/**
	斐波那契数列
	
	写一个函数，输入n，求斐波那契数列的第n项。
	f(n) = f(n-1) + f(n-2), f(0) = 0, f(1) = 1.

*/
long long fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	
	int a = 0;
	int b = 1;
	
	while (n > 1)
	{
		b += a;
		a = b - a;
		n--;
	}
	
	return b;
}