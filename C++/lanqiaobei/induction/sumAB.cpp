/**
	问题描述
		输入A、B，输出A+B。
		
	输入格式
		输入的第一行包括两个整数，由空格分隔，分别表示A、B。
		
	输出格式
		输出一行，包括一个整数，表示A+B的值。
		
	数据规模与约定
		-10000 <= A, B <= 10000。
*/

#include <iostream>

using namespace std;

int main(){
	int a = 0;
	int b = 0;
	while (cin >> a >> b){
		cout << (a + b) << endl;
	}
	return 0;
}

