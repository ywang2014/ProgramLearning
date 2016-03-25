/**
	字符串的左旋转
	
	字符串的左旋转操作，是把字符串前面的若干个字符转移到字符串的尾部。
	请定义一个函数实现字符串左旋转操作的功能。
	
	比如：输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab".
*/

char* leftRotationString(char* str, int length)
{
	if (str == NULL || length < 0)
	{
		return NULL;
	}
	
	char* left = new char[length];
	int rightLen = strlen(str) + 1 - length;
	char* right = new char[rightLen];
	char* rightIndex = (str + length);
	
	strncpy(left, str, length);
	strcpy(right, rightIndex);
	
	strcpy(str, right);
	strcat(str, left);
	
	delete[] left;
	delete[] right;
	
	return str;
}


/********************************** 参考代码  *****/
char* leftRotateString(char* str, int n)
{
	if (str == NULL)
	{
		return NULL;
	}
	
	int length = static_cast<int>(strlen(str));
	if (length > 0 && n > 0 && n < length)
	{
		char* firstStart = str;
		char* firstEnd = str + n - 1;
		char* secondStart = str + n;
		char* secondEnd = str + length - 1;
		
		reverseString(firstStart, firstEnd);
		reverseString(secondStart, secondEnd);
		
		reverseString(firstStart, secondEnd);
	}
	
	return str;
}