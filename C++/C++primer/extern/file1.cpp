/*
 Scope: 全局静态变量(外部链接性)、全局变量(内部链接性)
 ODR: 一次定义的原则
 小作用域变量自动覆盖全局变量
 variables with external and internal linkage
 to be compiled with file2.c
 */
#include <iostream>
int tom = 3;	// define external variable 
int dick = 10;	// ...
static int harry = 100;	// static internal linkage
int var = 1000;

void remote_global();
void remote_local();

int main()
{
	using namespace std;
	cout << "main() reports following addresses: \n";
	cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry. \n";
	remote_global();
	remote_local();
	return 0;
}