/*
	多参数函数
	
	模板参数包
	函数参数包
	
	g++ -std=c++11 variadic.cpp -o variadic
	objdump -d variadic.o > disassemble
*/
#include <iostream>
#include <string>

void show_list()
{
	//TODO
}

template<typename T>
void show_list(T value)
{
	std::cout << value << std::endl;
}

template<typename T, typename...Args>
void show_list(T value, Args... args)
{
	std::cout << value << ", ";
	show_list(args...);
}

int main()
{
	int n = 1;
	double x = 3.14;
	bool flag = true;
	std::string str = "Hello, world!";
	
	show_list(n, x);
	show_list(n, x, flag, str);
	
	return 0;
}

/******************************************************************
  optimize for class or big struct arguments
	
	reference is a good ideal
********************************************************************/
void show_list2()
{
	//TODO
}

template<typename T>
void show_list2(const T& value)
{
	std::cout << value << std::endl;
}

template<typename T, typename...Args>
void show_list2(const T& value, const Args&... args)
{
	std::cout << value << ", ";
	show_list(args...);
}
