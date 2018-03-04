#include <iostream>

using namespace std;

// 第三题：
// 最长的递增连续子序列的起始索引
int findLongestAscending(int *A, int n){
	if (A == nullptr || n < 1){
		return -1;	// invalid parameters
	}
	int maxLen = 1;
	int currentLen = 1;
	int startIndex = 0;
	int currentStartIndex = 0;
	for (int i = 0; i < n-1; i++){
		if (A[i] <= A[i+1]){
			currentLen++;
			if (maxLen < currentLen){
				maxLen = currentLen;
				startIndex = currentStartIndex;
			}
		} else {
			currentLen = 1;
			currentStartIndex = i+1;
		}
	}
	return startIndex;
}

// 第一题：
// 规整链表：负数节点在左边，正数节点在右边
struct Node{
	int value;
	struct Node *next;
}

typedef struct Node Node;	// 不多写struct了

void shuffleList(Node **head){
	if (head == nullptr){
		return ;	// invalid parameter
	}
	
	Node *currentHead = head[0];
	if (currentHead == nullptr){
		return ;
	}
	Node *currentNode = currentHead->next;
	while (currentNode != nullptr){
		Node * next = currentNode->next;
		// 负数节点，直接放在链表头部
		if (currentNode->value < 0){
			currentNode->next = currentHead;
			currentHead = currentNode;
		}
		currentNode = next;
	}
}

// 第二题：
// 二叉树，最低公共祖先节点
struct Node{
	int value;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
}

typedef struct Node node;	// 不多写struct了

struct Node *lowestCommonAncestor(struct Node *node1, struct Node *node2){
	if (node1 == nullptr || node2 == nullptr){
		return nullptr;
	}
	Node *node1List = node1;
	int node1ListLen = getNodeParentListLength(node1List);
	Node *node2List = node2;
	int node2ListLen = getNodeParentListLength(node2List);
	
	// 尾 对齐两个链表
	if (node1ListLen > node2ListLen){
		int offset = node1ListLen - node2ListLen;
		while (offset > 0){
			node1 = getParentNode(node1);
			offset--;
		}
	} else if (node1ListLen < node2ListLen){
		int offset = node2ListLen - node1ListLen;
		while (offset > 0){
			node2 = getParentNode(node2);
			offset--;
		}
	}
	
	while (node1 != nullptr && node2 != nullptr){
		if (node1->parent == node2->parent){
			return node1->parent;
		}
		node1 = getParentNode(node1);
		node2 = getParentNode(node2);
	}
	return nullptr;
}

int getNodeParentListLength(Node *node){
	int len = 0;
	while (node != nullptr){
		len++;
		node = getParentNode(node);
	}
	return len;
}

Node *getParentNode(Node *node){
	if (node != nullptr){
		return node->parent;
	}
	return nullptr;
}
