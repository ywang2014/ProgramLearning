/**
	顺时针打印矩阵
	
	输入一个矩阵，按照从外向里以顺时针的顺序，依次打印出每一个数字。
	例如：如果输入如下矩阵：
		1	2	3	4 
		5	6	7	8 
		9	10	11	12
		13 	14	15	16
	输出：1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 	
	
*/

void printMatrix(int** matrix, unsigned int row, unsigned int column)
{
	//
}


/*************************** 参考代码	**/
void printMAtrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
	{
		return ;
	}
	
	int start = 0;
	
	while (columns > start * 2 && rows > starts * 2)
	{
		printMatrixInCircle(numbers, columns, rows, start);
		
		++start;
	}
}

void printMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX = columns - 1 -start;
	int endY = rows - 1 - start;
	
	// 从左到右打印一行
	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		printNumber(number);
	}
	
	// for (int i = start + 1; i <= endY; ++i)
	// {
		// int number = numbers[i][endX];
		// printNumber(number);
	// }
	
	// for (int i = endX - 1; i >= start; --i)
	// {
		// int number = numbers[endY][i];
		// printNumber(number);
	// }
	
	// for (int i = endY - 1; i > start; --i)
	// {
		// int number = numbers[i][start];
		// printNumber(number);
	// }
	
	// 从上到下打印一列
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			printNumber(number);
		}
	}
	
	// 从右到左打印一行
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			printNumber(number);
		}
	}
	
	// 从下到上打印一行
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			int number = numbers[i][start];
			printNumber(number);
		}
	}
}