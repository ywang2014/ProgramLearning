/**
	stof算法实现
	
	字符串转化为浮点数
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

double str2f(string str)
{
	// 调用C语言库函数atof
	return atof(str.c_str());
}

double str2f(string str)
{
	// 借用sscanf()函数
	double result;
	sscanf(str, "%d", &result);
	return result;
}

