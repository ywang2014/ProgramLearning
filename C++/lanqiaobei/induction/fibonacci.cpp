/**
	问题描述
		Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。

		当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。

	输入格式
		输入包含一个整数n。
	输出格式
		输出一行，包含一个整数，表示Fn除以10007的余数。
		
	数据规模与约定
		1 <= n <= 1,000,000。
*/

#include <iostream>

using namespace std;

int fib(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	int a = 1;
	int b = 1;
	while (n > 2){
		a += b;
		b = a - b;
		n--;
		a %= 10007;
	}
	return a;
}

int main(){
	int n = 0;
	while (cin >> n){
		cout << fib(n) << endl;
	}
	return 0;
}