/*
滴滴笔试第一题：
	求2*2子矩阵的最大和
	输入：一个矩阵 1 2 3;3 4 5;6 7 8...
		需要解析输入：读取行数m, 列数n(C++不知道怎么解析，%d不能读取";"，%c解析太困难，根本不知道数字的大小)
		借助 java的split()函数，解析非常轻松
	输出：2*2的子矩阵，保证其和最大！
	思路：没有好办法，穷举！
	
*/

package Test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Matrix
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str_in = new String();
		str_in = br.readLine();	// 读取数据
		
		String num[] = str_in.split(";");	// 分割
		int m = num.length;	// 计算行
		int n = 0;
		
		String num1[] = num[0].split(" ");
		n = num1.length;	// 计算列
		
		int[][] arr = new int[m][n];
		int maxsum = 0;
		
		for (int i = 0; i < m; i++)
		{
			String[] num2 = num[i].split(" ");
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = Integer.parseInt((String)num2[j]);	// 数据转换为int
			}
		}
		
		int row = 0;
		int col = 0;
		
		for (int i = 0; i < m-1; i++)
		{
			for (int j = 0; j < n-1; j++)
			{
				int sum = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
				if (sum > maxsum)
				{
					maxsum = sum;
					row = i;
					col = j;
				}
			}
		}
		System.out.println(arr[row][col] + " " + arr[row][col+1]);
		System.out.println(arr[row+1][col] + " " + arr[row+1][col+1]);
	}
}
