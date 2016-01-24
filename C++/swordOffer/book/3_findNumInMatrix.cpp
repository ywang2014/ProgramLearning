/*
	二维数组中的查找
	在一个二维数组中，每一行都按照从左到右递增顺排序的，每一列都按照从上到下递增的顺序排序的，
	请完成一个函数，输入一个二维数组和一个整数，判断数组中是否含有该整数。
*/

bool findNum(int** matrix, int row, int column, int num)
{
	for (int i = row - 1, j = 0; i >= 0 && j < column; )
	{
		if (matrix[i][j] == num)
		{
			return true;
		}
		else if (matrix[i][j] < num)
		{
			j++;
		}
		else if (matrix[i][j] > num)
		{
			i--;
		}
	}
	
	return false;
}

// 参考答案
bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	
	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
			{
				--column;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}