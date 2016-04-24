/**
	脚手架
	
	测试驱动程序
*/

int main(){
	int t;
	int i;
	
	while (scanf("%d %d", &n, &t) != EOF){
		for (i = 0; i < n; i++){
			x[i] = 10 * i;
		}
		printf(" %d\n", binarysearch(t));
	}
	return 0;
}

/***************** 自动化测试  ************************/
#define s binarysearch
#define MAXN 1000000

int main(){
	int i;
	for (n = 0; n < MAXN; n++){
		printf("n = %d\n", n);
		// test distinct elements (plus one at the end)
		for (i = 0; i <= n; i++){
			x[i] = 10 * i;
		}
		for (i = 0; i < n; i++){
			assert(s(10 * i) == i);
			assert(s(10 * i - 5) == -1);
		}
		assert(s(10 * n - 5) == -1);
		assert(s(10 * n) == -1);
		
		// test equal elements
		for (i = 0; i < n; i++){
			x[i] = 10;
		}
		if (n == 0){
			assert(s(10) == -1);
		}
		else{
			assert(0 <= s(10) && s(10) < n);
		}
		
		assert(s(5) == -1);
		assert(s(15) == -1);
	}
	
	return 0;
}