/**
	欧几里得算法
*/

int gcd(int a, int b){
	if (a == 0 || b == 0){
		return 0;
	}
	
	if (a < 0){
		a = -a;
	}
	if (b < 0){
		b = -b;
	}
	
	if (a < b){
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	
	while (b != 0){
		a = a % b;
		a ^= b;
		b = a ^ b;
		a = a ^ b;
	}
	
	return a;
}