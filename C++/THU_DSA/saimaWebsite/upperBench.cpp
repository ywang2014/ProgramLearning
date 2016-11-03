/**
	题目描述									
		有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第m级，共有多少走法？
		注：规定从一级到一级有0种走法。
		
	输入
		输入数据首先包含一个整数n(1<=n<=100)，表示测试实例的个数，然后是n行数据，每行包含一个整数m，（1<=m<=40),表示楼梯的级数。
	输出
		对于每个测试实例，请输出不同走法的数量。
*/

#include <iostream>

using namespace std;

int fibo(int m);

int main(){
	int n = 0;
	while (cin >> n){
		int m = 0;
		for (int i = 0; i < n; i++){
			cin >> m;
			cout << fibo(m) << endl;
		}
	}
	return 0;
}

int fibo(int m){
	if (m == 1){
		return 0;
	}
	else if (m == 2){
		return 1;
	}
	int a = 1;
	int b = 2;
	while (m > 3){
		b += a;
		a = b - a;
		m--;
	}
	return b;
}