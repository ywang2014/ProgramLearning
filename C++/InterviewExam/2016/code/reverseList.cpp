struct Node {
	int val;
	Node *next;
}Node;

void reverse(Node *head) {
	// invalid parameter
	if (head == NULL){
		return ;
	}
	
	Node *currentNode = NULL;
	Node *nextNode = NULL;
	
	while (head != NULL){
		nextNode = head->next;
		head->next = currentNode;
		currentNode = head;
		head = nextNode;
	}
	
	head = currentNode;
}