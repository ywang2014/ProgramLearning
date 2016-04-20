/**
	字符串连接
	
	1. 英文字符串数组，其中英文单词是否可以构成一条路径，前一个单词的末尾字符，
	必须是后一个单词的第一个字符。如果可以则返回1，否则返回-1。

	如：["abc", "cde", "efg"], ["abc", "efg", "gfr", "cde"] ...是的
	["abc", "sde", "dec"] ...不是的
	
	假设英语单词都是合法字符，a-z, A-Z 		(Z-A - a) < 100
	
*/
	
int isStringsConcating(int num, char **arr){
	if (arr == NULL || num < 1){
		return -1;	// invalid arguments
	}
	
	char *str = NULL;	// 字符串
	char *firstCh = new char[num];	// 首字符
	char *lastCh = new char[num];	// 尾字符
	
	for (int i = 0; i < num; i++){
		str = arr[i];
		firstCh[i] = str[0];
		lastCh[i] = str[strlen(str)-1];
	}
	
	int hash[100] = {0};	// 存放字符出现次数的哈希表
	for (int i = 0; i < num; i++){
		++hash[firstCh[i] - 'a'];
		--hash[lastCh[i] - 'a'];	// 可以出现负的
	}

	int count = 0;
	for (int i = 0; i < 100; i++){
		if (hash[i] != 0){
			count++;
			if (count > 2){
				return -1;	// 多个奇数，肯定是不能的
			}
		}
	}
	
	return 1;
}