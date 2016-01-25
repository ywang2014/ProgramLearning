/*
	替换空格
	请实现一个函数，把字符串的每一个空格替换成“%20”。
	例如：
		输入"We are happy.", 
		输出"We%20are%20happy."。
*/

// 产生一个新串
char* replaceSpacing(const char* str)
{
	char *p = str;
	int countSpacing = 0;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			countSpacing++;
		}
		p++;
	}
	
	char* newStr = new char[strlen(str) + countSpacing * 2 + 1];
	
	int i = 0;
	for (p = str; *p != '\0'; p++)
	{
		if (*p == ' ')
		{
			newStr[i++] = '%';
			newStr[i++] = '2';
			newStr[i++] = '0';
		}
		else
		{
			newStr[i++] = *p;
		}
	}
	newStr[i] = '\0';
	return newStr;
}

// 原串修改
void replaceSpacing2(char* str)
{
	char* p = str;
	int countSpacing = 0;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			countSpacing++;
		}
		p++;
	}
	int offset = countSpacing * 2;
	
	while (*p != *str)	// 此时*p == '/0'，逆向移动
	{
		if (*p == ' ')
		{
			*(p + offset) = '0';
			*(p + offset - 1) = '2';
			*(p + offset - 2) = '%';
			offset -= 2;	// 等于0的时候，可以直接退出了，提高一点效率！
		}
		else
		{
			*(p + offset) = *p;
		}
		p--;
	}
}

void replaceBlank(char str[], int length)
{
	if (str == NULL || length <= 0)
	{
		return ;
	}
	
	int originalLen = 0;
	int numOfBlank = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		originalLen++;
		if (str[i] == ' ')
		{
			numOfBlank++;
		}
		i++;
	}
	
	int newLen = originalLen + numOfBlank * 2;
	if (newLen > length)
	{
		return ;
	}
	
	int indexOfOriginal = originalLen;
	int indexOfNew = newLen;
	while (0 <= indexOfOriginal && indexOfOriginal < indexOfNew)
	{
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOriginal];
		}
		
		indexOfOriginal--;
	}
}