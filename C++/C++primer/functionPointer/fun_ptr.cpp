/*
	pointer to functions
	函数指针的创建和调用方法！

*/

#include <iostream>

double betsy(int);
double pam(int);

void estimate(int lines, double (*pfun)(int));
// second argument is a pointer to a function, which must be the same as the function with return type and argument lists.

int main(void)
{
	using namespace std;
	
	int codes;
	cout << "How many lines of codes do you need?" << endl;
	while(cin >> codes)
	{
		cout << "Here is Betsy's estimate time: " << endl;
		estimate(codes, betsy);
		cout << "Here is Pam's estimate time: " << endl;
		estimate(codes, pam);
		cout << "How many lines of codes do you need?" << endl;
	}
	cout << "Estimating is ending! \n";
	
	return 0;
}

// 接受一个参数，用于与调用函数交互通信
double betsy(int lines)
{
	return 0.05 * lines;
}

double pam(int lines)
{
	return 0.03 * lines + 0.0003 * lines * lines;
}

void estimate(int lines, double (*pf)(int))
{
	using namespace std;
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " seconds.\n";	// 通过函数指针调用函数，并传入参数.
	// pf(lines)效果一样！两种方式都可以调用函数，返回结果。解释有些不同：*pf指代函数，pf函数指针！
	// 函数名是指代函数，也是指向函数代码首地址的函数指针！
}