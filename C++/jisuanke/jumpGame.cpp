/**
	跳跃游戏二：
	
	给定一个非负整数数组，假定你的初始位置为数组第一个下标。

	数组中的每个元素代表你在那个位置能够跳跃的最大长度。

	你的目标是到达最后一个下标，并且使用最少的跳跃次数。

	例如：

	A = [2,3,1,1,4], 到达最后一个下标的最少跳跃次数为2.（先跳跃1步，从下标0到1,然后跳跃3步，到达最后一个下标。一共两次）

	格式：

		第一行输入一个正整数n，接下来的一行，输入数组A[n]。

		最后输出最少的跳跃次数。

	样例1

		输入：
			5
			3 1 1 1 1
		输出：
			2
*/

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int * len = new int[n];		// 跳跃距离数组
		for (int i = 0; i < n; i++)
		{
			cin >> len[i];
		}
		
		int** dp = new int*[n];		// 动态规划数组 dp[i][j] = k 表示当前位置为i，且上一次跳跃距离为j时的最小次数为k
		for (int i = 0; i < n; i++)
		{
			dp[i] = new int[n];
		}
		
		// 初始化动态规划数组
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = n;	// 最大值
			}
		}
		
		// 初始化，起点处
		for (int j = 0; j <= len[0]; j++)
		{
			for (int i = len[0] - j; i >= 0; i--)
			{
				dp[i][j] = 1;	// 三角形区域，实际表示，这些地方，都是1次可以跳过去。如：dp[1][1] = dp[0][2]
			}
		}
		
		for (int k = 1; k < n; k++)
		{
			for (int j = 0; j <= len[k]; j++)
			{
				for (int i = k; i <= len[k] + k - j; i++)
				{
					if (i >= n)
					{
						continue;
					}
					// 还有逻辑错误
					dp[i][j] = min(dp[k][0]+1, dp[i-1][j+1]);	// 确定的实际就是到 i+j那个位置的代价。min(dp[0][i+j], dp[i-k][j+k], dp[i-1][j] + 1, ...)
				}
			}
		}
		
		cout << dp[n-1][0] << endl;
	}
	
	return 0;
}
