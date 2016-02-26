/**
	数值的整数次方
		
	题目：实现函数double Power(double base, int exponent), 求base的exponent次方。不得使用库函数，同时不需要考虑大数的问题。
*/

double power(const double base, int exponent)
{
	bool isPositive = true;
	if (exponent < 0)
	{
		isPositive = false;
		exponent = -exponent;
	}
	else if (exponent == 0)
	{
		if (base != 0)
		{
			return 1;	// n^0 = 1 (n!=0)
		}
		else 
		{
			throw new std::exception("Invalid arguments!");
		}
		
	}
	else if (base == 0)
	{
		return 0;	// 0^n = 0 (n!=0)
	}
	
	bool isOdd = false;
	double result = base;
	if (exponent % 2 == 1)
	{
		isOdd = true;
	}
	
	if (exponent == 1)
	{
		if (isPositive)
		{
			return result;
		}
		else
		{
			return 1 / result;
		}
	}
	
	while (exponent > 1)
	{
		//result = result * result;
		//exponent >> 1;	// 存在很多问题
		
		/***	还是不行，存在很多逻辑问题，比如：7		还是得递归啊！ */
		//if (exponent % 2)		// 
		//{
		//	result0 *= base;
		//}
		result = result * result;
		exponent >> 1;
	}
	
	if (isOdd)
	{
		result *= base;
	}
	
	if (isPositive)
	{
		return result;
	}
	
	return 1 / result;
}

// 递归方法
double power(const double base, int exponent)
{
	bool isPositive = true;
	if (exponent < 0)
	{
		isPositive = false;
		exponent = -exponent;
	}
	else if (exponent == 0)
	{
		if (base != 0)
		{
			return 1;	// n^0 = 1 (n!=0)
		}
		else 
		{
			throw new std::exception("Invalid arguments!");
		}
	}
	else if (base == 0)
	{
		return 0;	// 0^n = 0 (n!=0)
	}
	
	double powerBase(double base, int exponent)
	{
		// 退出递归
		if (exponent == 1)
		{
			return base;
		}
		else if (exponent == 2)
		{
			return base * base;
		}
		
		// 递归处理
		if (exponent % 2 == 1)
		{
			return power(power(base, exponent >> 1), 2) * base;
		}
		else
		{
			return power(power(base, exponent >> 1), 2);
		}
	}
	
	double result = powerBase(base, exponent);
	if (isPositive)
	{
		return result;
	}
	
	return 1 / result;
}


/****************** 	参考答案 ********/
bool g_InvalidInput = false;

double power(double base, int exponent)
{
	g_InvalidInput = false;
	
	if (equal(base, 0.0) && exponent != 0)
	{
		return 0.0;
	}
	else if (equal(base, 0.0) && exponent == 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	else if (exponent == 0)
	{
		return 1.0;
	}
	
	bool isPositive = true;
	if (exponent < 0)
	{
		isPositive = false;
		exponent = - exponent;
	}
	
	double result = powerWithPositiveExp(base, exponent);
	
	if (isPositive)
	{
		return result;
	}
	
	return 1.0 / result;	// 必须1.0
}

// 此函数0也可以正确处理
double powerWithPositiveExp(double base, int exponent)
{
	double result = 1.0;		// 1.0不是1
	for (int i = 1; i <= exponent; i++)
	{
		result *= base;
	}
	
	return result;
}

// 浮点数的比较，一定要特殊处理
bool equal(double a, double b)
{
	if ((a - b > -0.0000001) && (a - b < 0.0000001))
	{
		return true;
	}
	
	return false;
}