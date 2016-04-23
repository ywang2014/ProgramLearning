/**
	变位词程序
	
	sign程序，假定单词的长度不超过100个字母，并且输入文件只包含小写字符和换行符。
*/

int charcomp(char *x, char *y){
	return *x - *y;
}

#define WORDMAX 100

int main(void){
	char word[WORDMAX];
	char sig[WORDMAX];
	while (scanf("%s", word) != EOF){
		strcpy(sig, word);
		qsort(sig, strlen(sig), sizeof(char), charcomp);
		printf("%s %s\n", sig, word);
	}
	
	return 0;
}