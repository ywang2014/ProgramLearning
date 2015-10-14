/*
* an array of function pointers
* 函数指针数组的定义
* auto 自动生成类型的使用
* 输出结果的地址，是数组av中元素的地址，并非函数地址！
*/

# include <iostream>

const double * fn1(const double ar[], int n);
const double * fn2(const double [], int n);
const double * fn3(const double *ar, int n);
// 三个函数的类型本质是一模一样的！数组?=指针

int main()
{
	using namespace std;
	
	double av[3] = {1.1, 0.2, 1.3};
	
	// pointer to a function
	const double * (*pfun1)(const double *, int) = fn1;	// 替换法定义函数指针，同时初始化
	const double * (*pfun2)(const double *, int) = fn2;	// 	auto pfun2 = fn2;	// automatic type deduction. The same as 
	
	cout << "Using pointers to functions: \n";
	cout << "Address Value: \n";
	cout << (*pfun1)(av, 3) << " : " << *(*pfun1)(av, 3) << endl;
	cout << pfun2(av, 3) << " : " << *pfun2(av, 3) << endl;
	
	// pfunarr an array of pointers
	const double * (*pfunarr[3])(const double*, int) = {fn1, fn2, fn3};
	// Auto does not work with list initialization which only is used for a single value initialization
	// auto pfunb = pfunarr;
	cout << "\n--------------------------------------------\n";
	cout << "Using an array of pointers to functions: \n";
	cout << "Address value\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pfunarr[i](av, 3) << " : " << *pfunarr[i](av, 3) << endl;
	}
	
	cout << "\nUsing pointers to an array of function pointers:\n";
	cout << "Address value:\n";
	const double * (*(*pfunc)[3])(const double *, int) = &pfunarr;	// auto pfunc = &pfunarr;	// 
	cout << (*pfunc)[0](av, 3) << " : " << *(*pfunc)[0](av, 3) << endl;
	
	cin.get();
	
	return 0;
	
}

const double * fn1(const double ar[], int n)
{
	return ar;
}

const double * fn2(const double ar[], int n)
{
	return ar + 1;
}

const double * fn3(const double *ar, int n)
{
	return ar + 2;
}
