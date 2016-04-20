/**
	完美数

	2. 判断一个数字是否是完美数，完美数即一个数字刚好等于它所有因数的和，比如 28 = 1 + 2 + 4 + 7 + 14。
	输入一个int参数，输出，如果是完美数，则返回1，否则0。
	
*/
	
int isPerfectNumber(int num){
	if (num < 1){
		return 0;	// invalid arguments
	}
	int sum = num - 1;	// 1自动减去
	int lastIndex = num;
	for (int i = 2; i < lastIndex; i++){
		if (num % i == 0){
			lastIndex = num / i;
			sum = sum - i - lastIndex;
		}
	}
	
	return sum == 0;
}