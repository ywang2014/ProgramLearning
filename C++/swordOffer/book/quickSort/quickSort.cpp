/*
	递归实现，快速排序
*/

// 可以去掉length参数
void quickSort(int data[], int length, int start, int end)
{
	if (start == end)
	{
		return ;
	}
	
	int index = partition(data, length, start, end);
	
	if (index > start)
	{
		quickSort(data, length, start, index - 1);
	}
	
	if (index < end)
	{
		quickSort(data, length, index+1, end);
	}
}