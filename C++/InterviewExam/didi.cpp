/*
滴滴笔试第二题：
	求和为零的最长子数组
	输入：一个数组，元素可以有正数、负数和零
	输出：一个子数组！
		连续的数组，且其元素和为0
	类似：子数组最大和的题目。

*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[100];   // 假设数组元素不超过100个。
    int i = 0;
    int input = 0;
    while (scanf("%d", &input) != EOF)
    {
        arr[i++] = input;
    }

    int len = 0;
    int lo = 0;
    int hi = 0;

    for (int j = 0; j < i; j++)
    {
        int t = 0;
        int sum = arr[j];
        for (int k = j + 1; k < i; k++)
        {
            sum += arr[k];
            t++;
            if (sum == 0)
            {
                if (len < t)
                {
                    len = t;
                    lo = j;
                    hi = k;
                }
            }
        }
    }

    for (int j = lo; j <= hi; j++)
    {
        printf("%d ", arr[j]);
    }

    return 0;
}
