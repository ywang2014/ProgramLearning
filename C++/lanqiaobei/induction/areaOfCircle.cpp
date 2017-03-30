/**
	问题描述
		给定圆的半径r，求圆的面积。
	输入格式
		输入包含一个整数r，表示圆的半径。
	输出格式
		输出一行，包含一个实数，四舍五入保留小数点后7位，表示圆的面积。
	数据规模与约定
		1 <= r <= 10000。
*/
#include <iostream>

using namespace std;

double area(int r){
	return 3.14 * r * r;
}

int main(){
	int r = 0;
	while (cin >> r){
		// <iomanip>头文件   结果是7位宽，非7位小数
		cout << setprecision(7) << area(r) << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////
#include <stdio.h>

using namespace std;

double area(int r){
	const double PI = 3.14159265358979323846;
	return PI * r * r;
}

int main(){
	int r = 0;
	while (scanf("%d", &r) == 1){
		printf("%.7lf\n", area(r));
	}
	return 0;
}