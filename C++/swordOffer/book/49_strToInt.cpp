/**
	写一个 atoi()函数
	
	函数看似非常简单，但是细节地方非常多
	
	输入字符串指针为NULL，为空，非法字符等
*/
enum Status{ validParameter = 0, invalidParameter };

int g_status = validParameter;

int strToInt(const char* str)
{
	if (str == NULL || *str == '\0')
	{
		g_status = invalidParameter;
		return 0;
	}
	
	bool minus = false;
	
	if (*str == '-')
	{
		str++;
		minus = true;
	}
	else if (*str == '+')
	{
		str++;
	}
	
	if (*str == '\0')
	{
		g_status = invalidParameter;
		return 0;
	}
	
	long long result = 0;
	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			
			str++;
		}
		else 
		{
			g_status = invalidParameter;
			break;
		}
	}
	
	return minus ? 0 - result : result;
}