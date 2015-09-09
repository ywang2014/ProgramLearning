/*
 * main.cpp
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

/*
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
 * 思路是：从左到右遍历，从右到左替换
 */
#include <iostream>
#include <cstdio>

class ReplaceBlank
{
public:
	/*
	 // 版本一，有问题出现，返回之后，str并没有被修改！！！？？？
	void replaceSpace(char *str, int length)
	{
		char *p = str;
		str = new char[2 * length];
		int index = 0;
		for (int i = 0; i <= length; i++)
		{
			if (p[i] != ' ')
			{
				str[index++] = p[i];
			}
			else
			{
				str[index++] = '%';
				str[index++] = '2';
				str[index++] = '0';
			}
		}
		str[index] = '\0';
		printf("%s\n", str);
	}
	*/
	void replaceSpace(char *str, int length)
	{
		char *p = new char[length];
		for (int i = 0; i <= length; i++)
		{
			p[i] = str[i];
		}
		int index = 0;
		for (int i = 0; i <= length; i++)
		{
			if (p[i] != ' ')
			{
				str[index++] = p[i];
			}
			else
			{
				str[index++] = '%';
				str[index++] = '2';
				str[index++] = '0';
			}
		}
		str[index] = '\0';
		printf("%s\n", str);
	}
};

int main()
{
	char test[] = {"We Are Happy"};
	ReplaceBlank rb;
	rb.replaceSpace(test, 12);
	printf("%s\n", test);
	return 0;
}
