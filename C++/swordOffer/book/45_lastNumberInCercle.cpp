/**
	圆圈中最后剩下的数字
	
	0, 1, 2, ..., n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。
	求出这个圆圈里剩下的最后一个数字。
*/

struct ListNode
{
	int value;
	ListNode* next;
};

int lastNumber(unsigned int n, unsigned int m)
{
	if (n == 0 || m == 0)
	{
		std::throw new exception("Invalid parameter.");
	}
	
	ListNode* head = createNode(0);
	ListNode* node = head;
	
	for (int index = 1; index < n; index++)
	{
		ListNode* newNode = createNode(index);
		
		if (newNode != NULL)
		{
			node->next = newNode;
			node = node->next;
		}
		else
		{
			std::throw new exception("no enough memory.");
		}
	}
	
	// 构成循环链表
	node->next = head;
	
	ListNode* currentNode = head;
	while (currentNode->next != NULL)
	{
		//currentNode = head;	// 不是每次从头结点开始数的
		
		for (int index = 1; index < m; index++)
		{
			currentNode = currentNode->next;
		}
		
		// 如果被删除的是头结点，则移动头结点
		if (currentNode->next == head)
		{
			head = currentNode;
		}
		
		// 删除currentNode节点，O(1)的时间复杂度
		ListNode* delNode = currentNode->next;
		currentNode->value = delNode->value;
		currentNode->next = delNode->next;
		deleteNode(delNode);
	}
	
	return head->value;
}

ListNode* createNode(int number)
{
	ListNode* node = new ListNode();
	
	if (node == NULL)
	{
		return NULL;
	}
	
	node->value = number;
	node->next = NULL;
	
	return node;
}

void deleteNode(ListNode* node)
{
	delete node;
	node =NULL;
}



/****************** 参考代码	******/
int lastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	
	std::list<int> numbers;
	for (unsigned int i = 0; i < n; i++)
	{
		numbers.push_back(i);
	}
	
	std::list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			current++;
			if (current == numbers.end())
			{
				current = numbers.begin();
			}
		}
		
		std::list<int>::iterator dele = current;
		
		current++;
		if (current == numbers.end())
		{
			current = numbers.begin();
		}
		
		numbers.erase(dele);
	}
	
	return *current;
}


int lastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return ;
	}
	
	int *numbers = new int[n];
	for (unsigned int index = 0; index < n; index++)
	{
		numbers[index] = index;
	}
	
	return lastRemainingRecursive(numbers, n, m);
	
}

int lastRemainingRecursive(int* data, unsigned int n, unsigned int m)
{
	if (n == 1)
	{
		return data[0];
	}
	
	// 每次被删除的数字 k
	int k = (m - 1) % n;
	
	// 对数组进行映射处理
	for (unsigned int index = 0; index < n; index++)
	{
		data[index] = (n + index - k - 1) % n;
	}
	
	return lastRemainingRecursive(data, n-1, m);
}

// f(n, m) = ( f(n-1, m) + m ) % n 
// f(2, m) = ( f(1, m) + m ) % 2
// f(1, m) = 0	n为1时，只有一个数字0，即最后一个数，就是0
int lastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	
	int last = 0;
	for (int index = 2; index <= n; index++)
	{
		last = (last + m) % index;
	}
	
	return last;
}