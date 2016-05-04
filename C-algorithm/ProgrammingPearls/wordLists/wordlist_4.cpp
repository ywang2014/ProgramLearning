/**
	自定义实现散列表
*/

typedef struct node *nodeptr;
typedef struct node{
	char *word;
	int count;
	nodeptr next;
} node;

#define NHASH 29989
#define MULT 31

nodeptr bin[NHASH];

unsigned int hash(char *p){
	unsigned int h = 0;
	for (; *p; p++){
		h = MULT * h + *p;
	}
	
	return h % NHASH;
}

void incword(char *word){
	int h = hash(word);
	
	nodeptr p = bin[h]
	for (; p != NULL; p = p->next){
		if (strcmp(p->word, word) == 0){
			(p->count)++;
			break;	// return 
		}
	}
	if (p == NULL){
		p = malloc(sizeof(node));
		p->word = malloc(strlen(word) + 1);
		strcpy(p->word, word);
		p->count = 1;
		p->next = bin[h];
		bin[h] = p;
	}
}

int main(void){
	for (int i = 0; i < NHASH; i++){
		bin[i] = NULL;
	}
	
	char buf[100];	// 假设单词长度小于100字符
	while (scanf("%s", buf) != EOF){
		incword(buf);
	}
	
	for (int i = 0; i < NHAHS; i++){
		for (nodeptr p = bin[i]; p != NULL; p = p->next){
			printf("%s %d\n", p->word, p->count);
		}
	}
	
	return 0;
}