/**
	问题描述
		求1+2+3+...+n的值。
	输入格式
		输入包括一个整数n。
	输出格式
		输出一行，包括一个整数，表示1+2+3+...+n的值。
	数据规模与约定
		1 <= n <= 1,000,000,000。
*/

#include <iostream>

using namespace std;

int main(){
	int n = 0;
	while (cin >> n){
		// 越界溢出
		// cout << n * (n+1) / 2 << endl;
		long long sum = n + 1;
		cout << sum * (sum - 1) / 2 << endl;
	}
	return 0;
}