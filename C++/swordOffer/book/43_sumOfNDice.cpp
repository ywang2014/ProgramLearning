/**
	n个骰子的点数
	
	把n个骰子仍在地上，所有骰子朝上一面的点数之和为s。
	输入n，打印出s的所有可能的值出现的概率。
	
	思路：s的所有可能值 [n~6n]
	f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)
	
		n-1：第n个骰子点数为1
		n-2：第n个骰子点数为2
		n-3：第n个骰子点数为3
		...
*/

/**************** 参考代码 *******/
int g_maxValue = 6;

void printProbability(int number)
{
	if (number < 1)
	{
		return ;
	}
	
	int maxSum = number * g_maxValue;
	int* probabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i)
	{
		probabilities[i - number] = 0;
	}
	
	probability(number, probabilities);
	
	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i)
	{
		double ratio = (double)probabilities[i - number] / total;
		printf("%d: %e\n", i, ratio);
	}
	
	delete[] probabilities;
}


void probability(int number, int* probabilities)
{
	for (int i = 1; i <= g_maxValue; i++)
	{
		probability(number, number, i, probabilities);
	}
}

void probability(int original, int current, int sum, int* probabilities)
{
	if (current == 1)
	{
		probabilities[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; i++)
		{
			probability(original, current - 1, i + sum, probabilities);
		}
	}
}


// 基于循环的方法
void printPorbability(int number)
{
	if (number <１)
	{
		return ;
	}
	
	int* probabilities[2];
	probabilities[0] = new int[g_maxValue * number + 1];
	probabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; i++)
	{
		probabilities[0][i] = 0;
		probabilities[1][i] = 0;
	}
	
	int flag = 0;
	for (int i = 1; i <= g_maxValue; i++)
	{
		probabilities[flag][i] = 1;
	}
	
	for (int k = 2; k <= number; k++)
	{
		for (int i = 0; i < k; i++)
		{
			probabilities[1 - flag][i] = 0;
		}
		
		for (int i = k; i <= g_maxValue * k; i++)
		{
			probabilities[1 - flag][i] = 0;
			
			for (int j = 1; j <= i && j <= g_maxValue; j++)
			{
				probabilities[1 - flag][i] += probabilities[flag][i - j];
			}
		}
		
		flag = 1 - flag;
	}
	
	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; i++)
	{
		double ratio = (double)probabilities[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}
	
	delete[] probabilities[0];
	delete[] probabilities[1];
	
}

