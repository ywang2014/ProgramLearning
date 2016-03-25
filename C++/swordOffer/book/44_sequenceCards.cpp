/**
	扑克牌的顺子
	
	从扑克牌中随机抽取5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
	2-10为数字本身，A为1，J为11，Q为12，K为13，而大小王可以看成任意数字。
*/

bool isContinuous(int* numbers, int length)
{
	if (numbers == NULL || length < 1)
	{
		return false;
	}
	
	qsort(numbers, length, sizeof(numbers[0]), compare);
	
	int numbersOfZero = 0;
	int numbersOfGap = 0;
	
	// 已经排好序的数组
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		numbersOfZero++;
	}
	
	int low = numbersOfZero;
	int high = low + 1;
	while (high < length)
	{
		if (numbers[low] == numbers[high])
		{
			return false;
		}
		
		numbersOfGap += numbers[high] - numbers[low] - 1;
		
		low++;
		high++;
	}
	
	return (numbersOfGap > numbersOfZero) ? false : true;
}


int compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}