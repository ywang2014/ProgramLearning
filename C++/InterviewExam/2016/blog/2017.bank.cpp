/**
	2017年中国人民银行笔试-计算机专业
	第五题的测试程序
	一个6位数，与[2,6]中的任何一个数字的乘积还是一个6位数，而且6位数的组成数字没有变化，变化的
	只是6个组成数字的位置而已，请找出这些6位数。请使用推理方法，不能暴力穷举。
	
	测试结果表明，找不出来这样的6位数
*/
#include <iostream>
#include <fstream>

using namespace std;

void int2arr(int *arr, int n){
	int i = 0;
	while (n > 0){
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
}

void product(int *arr, int n, int num){
	int carry = 0;
	for (int i = 0; i < n; i++){
		arr[i] = arr[i] * num + carry;
		if (arr[i] > 9){
			carry = 1;
			arr[i] %= 10;
		}
		else{
			carry = 0;
		}
	}
}

bool isOk(int n){
	bool hash[10] = { 0 };
	for (int i = 0; i < 10; i++){
		hash[i] = false;
	}

	int arr[6] = { 0 };
	int2arr(arr, n);
	for (int i = 0; i < 6; i++){
		hash[arr[i]] = true;
	}

	for (int j = 2; j <= 6; j++){	// 任意2-6中的数字
		int brr[6] = { 0 };
		for (int i = 0; i < 6; i++){
			brr[i] = arr[i];
		}
		product(brr, 6, j);
		for (int i = 0; i < 6; i++){
			if (!hash[brr[i]]){
				return false;	// 非原来的数字，返回错误
			}
		}
	}
	return true;
}

int main(){
	fstream outfile;
	outfile.open("out.dat");
	for (int i = 100000; i < 200000; i++){
		bool res = isOk(i);
		outfile << i << " , " << res << endl;
		if (res){
			outfile << i << ", ok" << endl;
		}
	}
	return 0;
}