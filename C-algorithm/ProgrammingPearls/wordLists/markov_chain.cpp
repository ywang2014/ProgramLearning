/**
	生成order-k的马尔科夫链
*/

#include <iostream>

using namespace std;

int main(){
	int k = 2;
	char inputchars[5000000];
	char *word[1000000];
	int nword = 0;
	
	word[0] = inputchars;	// 是不是赋值反了？
	while (scanf("%s", word[nword]) != EOF){
		word[nword+1] = word[nword] + strlen(word[nword]) + 1;
		nword++;
	}
	
	for (int i = 0; i < k; i++){
		word[nword][i] = 0;
	}
	for (int i = 0; i < k; i++){
		printf("%s\n", word[i]);
	}
	qsort(word, nword, sizeof(word[0]), sortcmp);
	
	char *phrase = inputchars;
	for (int wordsleft = 10000; wordsleft > 0; wordsleft--){
		int l = -1;
		int u = nword;
		while (l+1 != u){
			int m = (l + u) / 2;
			if (wordncmp(word[m], phrase, k) < 0){
				l = m;
			}
			else{
				u = m;
			}
		}
		
		char *p;
		for (int i = 0; wordncmp(phrase, word[u+i]) == 0; i++){
			if (rand() % (i + 1) == 0){
				p = word[u + i];
			}
		}
		phrase = skip(p, 1);
		if (strlen(skip(phrase, k-1)) == 0){
			break;
		}
		printf("%s\n", skip(phrase, k-1));
	}
	
	return 0;
}

// k表示相同单词个数
int wordncmp(char *p, char *q, int k){
	int n = k;
	
	for (; *p == *q; p++, q++){
		if (*p == 0 && --n == 0){	// && 短路，遇见'\0'，说明找到一个相同的单词，故n--
			return 0;
		}
	}
	return *p - *q;
}

int sortcmp(char *p, char *q){
	return strcmp(p, q);
}