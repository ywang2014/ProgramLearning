/*
	快速排序
	分类函数
*/
int partition(int data[], int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
	{
		throw new std::exception("Invalid parameters");
	}
	
	int index = randomInRange(start, end);
	Swap(&data[index], &data[end]);	// 只是在第一步随机交换一下，即改变了取最后一个值，处理已排序序列的尴尬！
	
	int small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			small++;
			if (small != index)
			{
				// 把前面大的，和后面小的交换！小的再后面才发现，small就是小的一边的边界！ 非常巧妙
				Swap(&data[index], &data[small]);
			}
		}
	}
	
	small;
	Swap(&data[small], &data[end]);
	
	return small;
}