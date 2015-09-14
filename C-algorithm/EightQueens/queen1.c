/*
 * queen1.c
 *
 *  Created on: 2015-9-13
 *      Author: ZKY
 *      Recall without Recursion
 *  最原始暴力的解法：回溯、试探
 *  通俗易懂，逻辑简单(苦做了一天，被各种退出逻辑，回溯条件，边界条件弄晕了头！！！)
 */

#include <stdio.h>
#define QUEENS 8

void queen1(void);
int check(void);
int checkpoint(int i, int value);
int checkmodify(void);
void printBoard(void);
void init(void);


int states[9];	// 1,2,3...8 代表棋盘8列
int count = 0;	// 统计合适的结果数

int main(void)
{
	printf("Hello start...\n");
	//queen1();

	states[1] = 1;
	states[2] = 5;
	states[3] = 8;
	states[4] = 6;
	states[5] = 3;
	states[6] = 7;
	states[7] = 2;
	states[8] = 4;

	printf("%d\n", check());

	return 0;
}

// 主函数
void queen1(void)
{
	int k2, k3, k4, k5, k6, k7, k8;

	states[1] = 1;	// 启始位置，开始搜索

	while (states[1] < 9)
	{
		printf("%d:\n", states[1]);	// 第i颗树，states[1]为根节点。
		// i = 2;  // 使用 i 做标记很麻烦，回溯需要 i-- 的
		for (k2 = 1; k2 <= QUEENS; k2++)   // 第二列
        {
            if (checkpoint(2, k2) == 0)
            {
                states[2] = k2;
                for (k3 = 1; k3 <= QUEENS; k3++)    // 第三列
                {
                    if (checkpoint(3, k3) == 0)
                    {
                        states[3] = k3;
                        for (k4 = 1; k4 <= QUEENS; k4++)    // 第四列
                        {
                            if (checkpoint(4, k4) == 0)
                            {
                                states[4] = k4;
                                for (k5 = 1; k5 <= QUEENS; k5++)    // 第五列
                                {
                                    if (checkpoint(5, k5) == 0)
                                    {
                                        states[5] = k5;
                                        for (k6 = 1; k6 <= QUEENS; k6++)    // 第六列
                                        {
                                            if (checkpoint(6, k6) == 0)
                                            {
                                                states[6] = k6;
                                                for (k7 = 1; k7 <= QUEENS; k7++)   // 第七列
                                                {
                                                    if (checkpoint(7, k7) == 0)
                                                    {
                                                        states[7] = k7;
                                                        for (k8 = 1; k8 <= QUEENS; k8++)   // 第八列
                                                        {
                                                            if (checkpoint(8, k8) == 0)
                                                            {
                                                                states[8] = k8;
                                                                printBoard();
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
		states[1]++;	// 保证前进，不在原地方循环
	}
	printf("over!\n");
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

int checkmodify(void)
{
	int k;
	for (k = 1; k < QUEENS; k++)
	{
		if (states[k] > QUEENS)
		{
			return k;
		}
	}
	return 0;
}

void printBoard(void)
{
	int k;
	printf("Start output...\n");
	// 输出正确结果
	if (check() == 0)   // 可以不需要，成功退出的那一次，结果肯定就是正确，否则 checkpoint()不成功
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



