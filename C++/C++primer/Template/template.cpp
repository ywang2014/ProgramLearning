/**
*	C++ 模板的应用
*		模板可以非常方便的生成一类函数：如同函数重载！
*	将同一算法用于不同类型的数据操作时，请用模板！
*
*	反汇编查看模板的原理：
*		最终代码中，没有模板函数，只有用到的模板函数的确定的函数定义
*		没有使用的模板函数，看不见任何函数定义！
*/

#include <iostream>

template <typename T>
void mySwap(T &operator1, T &operator2);

template <typename T>
void mySwap(T *arr1, T *arr2, int n);

template <typename T>
void showArray(T *arr, int n);

int main(void)
{
	using namespace std;
	
	int a = 2, b =3;
	
	cout << "Before using swap: \n";
	cout << "a = " << a << "; b = " << b << endl;
	
	mySwap(a, b);
	cout << "After using swap: \n";
	cout << "a = " << a << "; b = " << b << endl;
	
	double value1 = 1.0, value2 = 2.3;
	cout << "Before using swap: \n";
	cout << "value1 = " << value1 << "; value2 = " << value2 << endl;
	
	mySwap(value1, value2);
	cout << "After using swap: \n";
	cout << "value1 = " << value1 << "; value2 = " << value2 << endl;
	
	float x = 3.14f, y = 1.414f;
	cout << "Before using swap: \n";
	cout << "x = " << x << "; y = " << y << endl;
	
	mySwap(x, y);
	cout << "After using swap: \n";
	cout << "x = " << x << "; y = " << y << endl;
	
	return 0;
}

// function template definition
template <typename T>	// you can use class T instead of typename T
void mySwap(T &operator1, T &operator2)
{
	T temp = operator1;
	operator1 = operator2;
	operator2 = temp;
}

// using override template function
template <typename T>
void mySwap(T *arr1, T *arr2, int n)
{
	T temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}

template <typename T>
void showArray(T *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}