/**
	给定输入文本文件，查找其中最长的重复子字符串
	
	后缀数组
*/

#define MAXN 5000000
char c[MAXN];
char *a[MAXN];

int comlen(char *p, char *q){
	int i = 0;
	while (*p && (*p++ == *q++)){
		i++;
	}
	return i;
}

int main(void){
	char ch;
	int index = 0;
	while ((ch = getchar()) != EOF){
		c[index] = ch;
		a[index] = &c[index];
		index++;
	}
	c[index] = '\0';
	int len = index;
	
	qsort(a, len, sizeof(char *), pstrcmp);
	
	int maxlen = -1;
	int maxi;
	for (int i = 0; i < len; i++){
		int currentLen = comlen(a[i], a[i+1]);
		if ( currentLen > maxlen ){
			maxlen = currentLen;
			maxi = i;
		}
	}
	printf("%.*s\n", maxlen, a[maxi]);
	
	return 0;
}

int pstrcmp(char *p, char *q){
	return strcmp(p, q);
}
