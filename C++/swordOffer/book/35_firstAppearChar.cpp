/**
	第一个只出现一次的字符
	
	在字符串中找出第一个只出现一次的字符。
	
	如输入"abaccdeff"，则输出'b'.
*/

// 普通直接解法
char getFirstCharacterOnceAppearInString(const char* str)
{
	if (str == NULL)
	{
		return ;
	}
	
	int* alphabet = new int[26];
	for (unsigned int index = 0; index < 26; index++)
	{
		alphabet[index] = 0;
	}
	
	
	while (*str != '\0')
	{
		alphabet[*str - 'a'] ++;
		str++;
	}
	
	char result = '\0';
	for (unsigned int index = 0; index < 26; index++)
	{
		if (alphabet[index] = 1)
		{
			result = 'a' + index;
			break;
		}
	}
	
	delete[] alphabet;
	
	return result;
}


/************************** 参考代码 *****/
char firstNotRepeatingChar(char* str)
{
	if (str == NULL)
	{
		return '\0';
	}
	
	const int tableSize = 256;	// ASCII值范围
	unsigned int hashTable[tableSize];
	for (unsigned int index = 0; index < tableSize; index++)
	{
		hashTable[index] = 0;
	}
	
	char* hashKey = str;
	while (*hashKey != '\0')
	{
		//hashTable[*(hashKey++)] ++;
		hashTable[*hashKey] ++;
		hashKey++;
	}
	
	hashKey = str;
	while (*hashKey != '\0')
	{
		if (hashTable[*hashKey] == 1)
		{
			return *hashKey;
		}
		
		hashKey++;
	}
	
	return '\0';
}