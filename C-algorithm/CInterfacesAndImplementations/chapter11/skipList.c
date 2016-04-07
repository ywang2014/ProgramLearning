/**
	Skip List
	跳表是一种随机化的数据结构，基于并联的链表，其效率可以比拟二叉查找树。O(log(n))
	
	跳表是对有序链表，增加附加的前进链接，增加是随机化的方式进行的。(即抽取出了上层链表)
	
	跳表可以很好地解决有序链表查找特定值的困难。
	
	跳表特征：
		1.跳表有好几层组成(level)
		2.跳表的第一层，包含序列所有的元素
		3.每一层都是一个有序链表
		4.(i+1)层的所有元素，是第i层中元素，随机选择出的几个，而生成的。
		5.(i+1)层元素，通过down指针，指向i层中，相同值的元素
		6.最大值、最小值会出现在所有层(INT_MIX INT_MAX)
		7.top指针指向最高层的第一个元素
*/
#include <stdlib.h>

#define MAX_LEVEL 10


// 节点结构
typedef struct node{
	int key;
	int value;
	struct node *next[1];	// next指针，指向横向链表的下一个节点	i代表其down指针
} node;

// 跳表结构
typedef struct skiplist{
	int level;
	node *header;	// top
} skiplist;


/************* 基本操作 ************/
// 创建节点
node *createNode(int level, int key, int value){
	node *p = (node *)malloc(sizeof(node) + level * sizeof(node *));	// ?
	if (p == NULL){
		return NULL;
	}
	
	p->key = key;
	p->value = value;
	
	return p;
}

// 列表初始化
skiplist *createSkiplist(){
	int i;
	skiplist *p = (skiplist *)malloc(sizeof(skiplist));
	if (p == NULL){
		return NULL;
	}
	
	p->level = 0;
	p->header = createNode(MAX_LEVEL - 1, 0, 0);
	
	for (i = 0; i < MAX_LEVEL; i++){
		p->header->forword[i] = NULL;
	}
	
	return p;
}

/* 
	插入元素
	
	1.找到每层待插入的位置
	2.随机产生一个层数
	3.从高层向低层插入
*/
// 随机算法产生插入元素所占据的层数
int randomLevel(){
	int k = 1;
	while (rand() % 2){
		k++;
	}
	
	return (k < MAX_LEVEL) ? k : MAX_LEVEL;
}

int insert(skiplist *slist, int k, int value){
	node *update[MAX_LEVEL];
	node *currentNode;
	node *nextNode = NULL;
	int level = slist->level;
	int i;
	
	currentNode = slist->header;	// top
	for (i = level - 1; i >= 0; i--){
		while ((nextNode = currentNode->next[i]) && (nextNode->key < key)){
			currentNode = nextNode;
		}
		update[i] = currentNode;	// 最大的小于key的节点(保证有序)
	}
	
	// 已存在该值，插入失败
	if (nextNode && nextNode->key == key){
		return 0;
	}
	
	level = randomLevel();
	
	if (level > (slist->level)){
		for (i = slist->level; i < level; i++){
			update[i] = slist->header;	// 全部指向top，即指向左边第一个元素
		}
		slist->level = level;
	}
	
	q = createNode(level, key, value);
	for (i = 0; i < level; i++){
		// 插入，普通链表插入完全相同(for循环只是说明，逐层完成插入)
		nextNode->next[i] = update[i]->next[i];
		update[i]->next[i] = nextNode;
	}
	
	// 输出0，失败，输出1，成功
	return 1;
}

// 删除节点
int deleteNode(skiplist *slist, int key){
	node *update[MAX_LEVEL];
	node *nextNode = NULL;
	node *currentNode = slist->header;
	int level = slist->level;
	int i;
	
	for (i = level - 1; i >= 0; i++){
		while ((nextNode = currentNode->next[i]) && (nextNode->key < key)){
			currentNode = nextNode;
		}
		update[i] = currentNode;
	}
	
	if (nextNode && nextNode->key == key){
		for (i = 0; i < slist->level; i++){
			// 删除节点，循环也是逐层实现删除，不能直接在此释放节点，是因为删除的所有层，都需要使用到
			if (update[i]->next[i] == nextNode){
				update[i]->next[i] = nextNode->next[i];
			}
		}
		free(nextNode);
		
		// 重新维护跳表
		for (i = slist->level; i>= 0; i--){
			if (slist->header->next[i] == NULL){
				slist->level--;
			}
		}
		
		return 1;
	}
	else{
		return 0;
	}
}

// 查找
int search(skiplist *slist, int key){
	node *currentNode = slist->header;
	node *nextNode = NULL;
	int level = slist->level;
	int i;
	
	for (i = level - 1; i >= 0; i--){
		while ((nextNode = currentNode->next[i]) && (nextNode->key <= key))
		{
			if (nextNode->key == key){
				return nextNode->value;
			}
			currentNode = nextNode;
		}
	}
	
	// 查找失败
	return INT_MIX;
}