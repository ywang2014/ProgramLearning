/*
 * queen2.c
 *
 *  Created on: 2015-9-13
 *      Author: ZKY
 *      Recursion
 */


#include <stdio.h>
#include <stdlib.h>
#define QUEENS 8

int queen1(void);
int check(void);
int checkpoint(int i, int value);
void printBoard(void);
void init(void);


int states[9];	// 1,2,3...8 代表棋盘8列
int count = 0;	// 统计合适的结果数

int main(void)
{
	printf("Hello start...\n");
	queen2();
}

// 主函数
int queen2(int i)
{
	/*
	int k;

	for (k = 1; k <= QUEENS; k++)
	{
		if (i == QUEENS)	// 递归退出条件
		{
			if (checkpoint(i, k) == 0)
			{
				states[i] = k;

				printBoard();
			}

			return ;
		}
		else
		{
			if (checkpoint(i, k) == 0)
			{
				states[i] = k;

				queen2(i + 1);
			}
			else	// 回溯到上一层
			{
				if (i == 1)
				{
					exit();	// 搜索完成
				}

				i--;

				for (k = states[i] + 1; k <= QUEENS; k++)
				{
					if (checkpoint(i, k) == 0)
					{
						states[i] = k;
						queen2(i + 1);
					}
				}
			}
		}
	}
	*/

	int k = 1;

	while (k <= QUEENS)	// 在循环中查找一遍
	{
		if (checkpoint(i, k) == 0)
		{
			states[i] = k;
			if (i == 8)
			{
				printBoard();
				return ;
			}
			else
			{
				queen2(i + 1);
			}
		}
		else
		{
			k++;
		}
	}

	/*
	 * 想明白了，开始以为 for 不行，实际 for 比 while 更加简洁。
	int k;
	for (k = 1; k <= QUEENS; K++)
	{
		if (checkpoint(i, k) == 0)
		{
			states[i] = k;
			if (i == 8)
			{
				printBoard();
				return ;
			}
			else
			{
				queen2(i + 1);
			}
		}
	}

	*/

}

// 检查棋盘状态是否合法
int check(void)
{
	int i, j;

	for (i = 1; i < QUEENS; i++)
	{
		for (j = i + 1; j <= QUEENS; j++)
		{
			// 保证每行每列只有一个皇后
			if (states[i] == states[j])
			{
				return -1;
			}

			// 保证对角线上只有一个皇后
			if ((states[i] - states[j]) == (i - j) || (states[i] - states[j]) == (j - i))
			{
				return -1;
			}
		}
	}

	return 0;
}

// 检查 第i列放在第value行处是否安全
int checkpoint(int i, int value)
{
	int j;

	for (j = 1; j < i; j++)	// 只需要考虑排放好了的！！！（既可以不用初始化）
	{
		if (value == states[j])
		{
			return -1;
		}

		// 保证对角线上只有一个皇后
		if ((value - states[j]) == (i - j) || (value - states[j]) == (j - i))
		{
			return -1;
		}
	}

	return 0;
}

void printBoard(void)
{
	int k;
	printf("Start output...\n");
	// 输出正确结果
	if (check() == 0)
	{
		count++;
		printf("count%d\t: ", count);
		for (k = 1; k <= QUEENS; k++)
		{
			printf("%d ", states[k]);
		}
		printf("\n");
	}
}

void init(void)
{
	int k = 2;
	for (k = 2; k <= QUEENS; k++)
	{
		states[k] = 0;
	}
}


