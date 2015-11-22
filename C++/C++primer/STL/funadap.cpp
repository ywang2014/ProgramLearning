/**
	STL
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void show(double e);
const int LIM = 6;

int main()
{
	using namespace std;
	
	double arr1[LIM] = {28, 12, 23, 34, 38};
	double arr2[LIM] = {45, 55, 65, 75, 85};
	
	vector<double> vecd1(arr1, arr1+LIM);	// 创造一个vector<double>对象
	vector<double> vecd2(arr2, arr2+LIM);	// 创造一个vector<double>对象
	
	cout.setf(ios_base::fixed);	// 设置输出格式
	cout.precision(1);
	
	cout << "vecd1:\t";
	for_each(vecd1.begin(), vecd1.end(), show);	// for_each 函数
	cout << end;
	
	vector<double> sum(LIM);	// 创造一个vector<double>对象
	transform(vecd1.begin(), vecd1.end(), vecd2.begin(), sum.begin(), plus<double>());
	/*
		transform() 函数
		plus<T> 函数类
		obj.begin()/obj.end()迭代器：广义指针
		匿名函数对象
	*/
	cout << "sum:\t";
	for (double x: sum)	// 基于范围的for循环
	{
		show(x);
	}
	cout << endl;
	
	vector<double> produc(LIM);		// 创造一个vector<double>对象
	multiplies<double> times;		// 创造一个multiplies<double>对象
	bind1st(times, 1.2) times12;	// 创造一个bind1st对象
	// bind1st(multiplies<double>(), 1.2) 匿名构造
	transform(vecd1.begin(), vecd1.end(), produc.begin(), times12);
	cout << "produc:\t";
	for (double x: produc) show(x);
	cout << endl;
	
	return 0;
}

void show(double value)
{
	std::cout.width(6);
	std::cout << value << ' ';
}