/*
	把字符串准换为整数
*/
int str2Int(const char* str)
{
	if (str == NULL)	// 空指针
	{
		return 0;
	}
	
	char* p = str;
	int num = 0;
	bool plus_sign = true;
	
	if (*p == '+')	// 处理符号位
	{
		p++;
	}
	else if (*p == '-')
	{
		plus_sign = false;
		p++
	}
	
	while ((*p != 0) && (*p >= '0') && (*p <= '9'))
	{
		num = num * 10 + (*p - '0');
		p++;
	}
	
	if (!plus_sign)	// 负数
	{
		num = -num;
	}
	
	return num;
}
