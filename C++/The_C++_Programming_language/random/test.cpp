/**
	随机数生成器测试程序
*/

#include <iostream>
#include "randint.hpp"

int main(){
	Urand draw(10);	// 声明一个对象
	
	map<int, int> bucket;
	for (int i = 0; i < 1000000; i++){
		bucket[draw()]++;	// 调用对象函数 operator()();
	}
	for (int j = 0; j < 10; j++){
		std::cout << bucket[j] << '\n';		// 除非每个bucket里的值，都接近100000，否则程序一定出现了错误。
	}
}
