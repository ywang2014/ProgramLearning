/**
	变位词程序
	
	squash程序，将变位词输出在单行中
*/
int main(void){
	char word[WORDMAX];
	char sig[WORDMAX];
	char oldSig[WORDMAX];
	int lineNum = 0;
	
	strcpy(oldSig, "");
	while (scanf("%s %s", sig, word) != EOF){
		if (strcmp(oldSig, sig) != 0 && lineNum > 0){
			printf("\n");
		}
		strcpy(oldSig, sig);
		lineNum++;
		printf("%s ", word);
	}
	printf("\n");
	
	return 0;
}