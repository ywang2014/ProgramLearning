/**
	打印出所有和为s的序列(至少两个数)
	
	输入正数s，打印出所有和为s的连续正数序列(至少含有两个数)。
	
	例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列：1~5 4~6 7~8
	
	注意：连续正数序列
*/

void findContinuousSequence(int sum)
{
	if (sum < 3)
	{
		return ;
	}
	
	int low = 1;
	int high = 2;
	int middle = (1 + sum) / 2;
	int currentSum = low + high;
	
	while (low < middle)
	{
		if (currentSum == sum)
		{
			printSequence(low, high);
		}
		
		while (currentSum > sum && low < middle)
		{
			currentSum -= low;
			low++;
			
			if (currentSum == sum)
			{
				printSequence(low, high);
			}
		}
		
		high++;
		currentSum += high;
	}
}


// 输出正数序列
void printSequence(int low, int high)
{
	while (low < high)
	{
		printf("%d ", low);
		low++;
	}
	
	printf("%d\n", high);
}