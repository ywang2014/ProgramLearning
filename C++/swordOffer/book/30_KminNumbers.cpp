/**
	最小的k个数
	
	输入n个整数，找出其中最小的k个数。
	
	例如：输入4, 5, 1, 6, 2, 7, 3, 8
		  输出最小的4个数：1, 2, 3, 4 
*/

// 思路一：直接排序，输出最小的k个数，时间复杂度：O(nlog(n))
void printKminNumbers(int* data, unsigned int length, unsigned int k)
{
	if (data == NULL || length == 0 || k >= length)
	{
		return ;
	}
	
	// 系统自带排序算法！
	// C语言	void qsort ( void * base, size_t num, size_t size, int ( * comparator ) ( const void *, const void * ) );
	// C++语言	sort(begin, end, compare)
	sort( data, data + length );
	// qsort(data, length, sizeof(data[0]), cmp)
	
	printNumbers(data, length, k);
}


void printNumbers(int* data, int length, int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", data[i]);
	}
}


// 思路二：借助快速排序思想
void printKminNumbers(int* data, unsigned int length, unsigned int k)
{
	// 参数处理
	if (isInvalid)
	{
		return ;
	}
	
	int index = partition(data, length, 0, length - 1);
	if (index = k-1)
	{
		printNumbers(data, length, k);
		return ;
	}
	else if (index < k-1)
	{
		printNumbers(data, length, index+1);
		printKminNumbers(data + index + 1, length - index - 1, k - index - 1);
	}
	else
	{
		printKminNumbers(data, index, k);
	}
}


/************************* 参考代码 **/
void getLeastNumber(int* input, int n, int* output, int k)
{
	if (input == NULL || output == NULL || k > n || n <= 0 || k <= 0)
	{
		return ;
	}
	
	int start = 0;
	int end = n - 1;
	int index = partition(input, n, start, end);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(input, n, start, end);
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		output[i] = input[i];
	}
}

// 基于STL中multiset实现的代码
typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIT;

void getLeastNumber(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();
	
	if (k < 1 || data.size() < k)
	{
		return ;
	}
	
	typedef vector<int>::const_iterator vectorCIT;
	for (vectorCIT iter = data.begin(); iter != data.end(); iter++)
	{
		if (leastNumbers.size() < k)
		{
			leastNumbers.insert(*iter);
		}
		else 
		{
			setIT iterGreatest = leastNumbers.begin();
			if (*iter < *iterGreatest)
			{
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}