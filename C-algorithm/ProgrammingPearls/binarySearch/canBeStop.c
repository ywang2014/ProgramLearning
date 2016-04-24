/**
	验证x为正数时，程序是否会终止
	如果 x != 1：
		x为偶数 x = x / 2
		x为奇数 x = 3 * x + 1
	重复操作 x
*/
#include <stdio.h>

int main(void){
	int x = 0;
	int count = 0;
	
	printf("please input the test number x: ");
	scanf("%d", &x);
	assert(x > 0);
	while (x != 1){
		if ((x & 0x1) == 0){
			x /= 2;
		}
		else{
			x = 3 * x + 1;
		}
		count++;
	}
	printf("%d\n", count);
}