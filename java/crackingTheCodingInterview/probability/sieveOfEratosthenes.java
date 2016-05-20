/**
	埃拉托斯特尼筛选法
*/
boolean[] sieveOfEratosthenes(int max){
	boolean[] flags = new boolean[max + 1];
	int count = 0;
	
	// init
	for (int i = 2; i <= max; i++){
		flags[i] = true;
	}
	int prime = 2;
	
	while (prime <= max){
		crossOff(flags, prime);
		
		prime = getNextPrime(flags, prime);
		
		if (prime >= flags.length){
			break;
		}
	}
	
	return flags;
}

// 剔除prime的倍数
void crossOff(boolean[] flags, int prime){
	for (int i = prime * prime; i < flags.length; i += prime){	// 2(3,5...)*prime早被2划掉了...
		flags[i] = false;
	}
}

int getNextPrime(boolean[] flags, int prime){
	int next = prime + 1;
	while (next < flags.length && !flags[next]){
		next++;
	}
	
	return next;
}


int getNextPrime(boolean[] flags, int prime){
	for (int i = prime + 1; i < flags.length; i++){
		if (flags[i]){
			prime = i;
			break;
		}
	}
	
	return prime;	// 可能原地循环， i = ++prime即可
}