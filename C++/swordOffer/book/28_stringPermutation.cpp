/**
	字符串的排列
	
	输入一个字符串，打印出该字符串中字符的所有排列。
	
	例如：输入字符串"abc"，则打印出由字符a、b、c所能排列出来的所有字符串abc、bac、bca、cab和cba
*/
inline void swap(char& first, char& second)
{
	char firstData = first;
	first = second;
	second = firstData;
}

void printStringPermutation(char* str)
{
	if (str == NULL)
	{
		return ;
	}
	
	permutation(str, str);
}

void permutation(char* str, char* begin)
{
	// 递归出口
	if (begin == '\0')
	{
		printf("%s", str);
		return ;
	}
	
	for (char* ch = begin; ch != '\0'; ch++)
	{
		// 交换第一次，即不交换的情况下的排列
		swap(*ch, *begin);
		
		permutation(str, begin+1);
		
		swap(*ch, *begin);
	}
}