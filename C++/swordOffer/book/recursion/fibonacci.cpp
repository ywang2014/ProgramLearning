/**
	递归函数：
	
	斐波那契数列
*/

long long fibonacci(unsigned int n)
{
	if (n == 0)
	{
		return 0
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

// 数组存储前面计算好的值，直接查表
const int SIZE = 1000;
static long long fibo[SIZE];
long long fibonacci(unsigned int n)
{
	fibo[0] = 0;
	fibo[1] = 1;
	
	for (int i = 2; i < SIZE; i++)
	{
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	
	return n < SIZE ? fibo[n] : 0;
}

// 自底向上计算
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

/**
	O(log(n))解法
	f(n) 	f(n-1) 	=	1 1  *  f(n-1) 	f(n-2) 
	f(n-1)	f(n-2)		1 0		f(n-2)	f(n-3)
*/
long long fibonacci(unsigned int n)
{
	long long *matrix;
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	
	matrix = fiboPro(n-1);
	
	return matrix[0];
}

// 矩阵乘法
long long** product(const long long** matrix1, const long long** matrix2, int n)
{
	long long** matrix = new *long long[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new long long[n];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	
	return matrix;
}

// 专门用于fibonacci的乘法
long long* fiboPro(int n)
{
	long long* matrix = new long long[4];
	matrix[0] = 1;
	matrix[1] = 1;
	matrix[2] = 1;
	matrix[3] = 0;
	
	if (n < 1)
	{
		throw new std::exception("Invalid parameters");	// 非法
	}
	else if (n == 1)
	{
		return matrix;
	}
	else if (n == 2)
	{
		return pro(matrix, matrix);
	}
	
	if (n % 2 == 1)
	{
		return pro(pro(fiboPro(matrix, n/2)), matrix);
	}
	else
	{
		return pro(fiboPro(matrix, n/2));
	}
}

long long* pro(const long long* matrix1)
{
	const int LEN = 4;
	long long* matrix = new long long[LEN];
	
	matrix[0] = matrix1[0] * matrix1[0] + matrix1[1] * matrix1[2];
	matrix[1] = matrix1[0] * matrix1[1] + matrix1[1] * matrix1[3];
	matrix[2] = matrix1[2] * matrix1[0] + matrix1[3] * matrix1[2];
	matrix[3] = matrix1[2] * matrix1[1] + matrix1[3] * matrix1[3];
	
	return matrix;
}

long long* pro(const long long* matrix1, const long long* matrix2)
{
	const int LEN = 4;
	long long* matrix = new long long[LEN];
	
	matrix[0] = matrix1[0] * matrix2[0] + matrix1[1] * matrix2[2];
	matrix[1] = matrix1[0] * matrix2[1] + matrix1[1] * matrix2[3];
	matrix[2] = matrix1[2] * matrix2[0] + matrix1[3] * matrix2[2];
	matrix[3] = matrix1[2] * matrix2[1] + matrix1[3] * matrix2[3];
	
	return matrix;
}

// 非递归的fibonacci，矩阵乘法
void fiboPro(long long* matrix, int n)
{
	bool odd = false;
	if (n % 2 == 1)
	{
		odd = true;
	}
	
	while (n > 1)
	{
		matrix = pro(matrix);
		n >> 1;
	}
	
	if (odd)
	{
		long long* matrix0 = {1, 1, 1, 0};
		matrix = pro(matrix, matrix0);
	}
}

