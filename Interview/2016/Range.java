/**
	汽车之友，笔试题目
	输出数字区间：
		相邻的合并，不相邻的属于两个区间
	输入：6 1 2 3 6 9 10
	输出：
		1-3
		6-6
		9-10
		
	注意：小心一个值得情况，处理最后一个值！
	
*/

package Test;

import java.util.Scanner;

public class Range
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		
		int[] arr = new int[num];
		
		for (int i = 0; i < num; i++)
		{
			arr[i] = sc.nextInt();
		}
		
		sc.close();
		
		java.util.Arrays.sort(arr);
		
		for (int i = 0; i < num; i++)
		{
			if (i == 0)
			{
				System.out.print(arr[i]);
			}
			else
			{
				
				if (arr[i] != arr[i-1] + 1)
				{
					System.out.print('-');
					System.out.print(arr[i-1]);
					System.out.println();
					System.out.print(arr[i]);
				}
				
				/*
					不能和上一个if合并，，这个地方，必须再输出一次的，和上一个if不是重复
					可以放在后面的if中，不需要判断，直接输出两行。因为输出最后一个数，是必须的，不管多少数字都是一样！
				*/
				if (i + 1 == num)	
				{
					System.out.print('-');
					System.out.print(arr[i]);
				}
			}
		}
		
		if (num == 1)
		{
			System.out.print('-');
			System.out.print(arr[num-1]);
		}
	}
}

/***********************************************
 * 
public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		
		int[] arr = new int[num];
		
		for (int i = 0; i < num; i++)
		{
			arr[i] = sc.nextInt();
		}
		
		sc.close();
		
		java.util.Arrays.sort(arr);
		
		int flag = 0;
		for (int i = 0; i < num; i++)
		{
			System.out.print(arr[i]);
			
			if (i + 1 < num)
			{
				if (arr[i] == arr[i+1] - 1)
				{
					System.out.print('-');
				}
				else
				{
					if (flag != arr[i])
					{
						if (i == 0)
						{
							System.out.print('-');
							System.out.print(arr[i]);
						}
					}
					else
					{
						System.out.print('-');
						System.out.print(arr[i]);
						
					}
					System.out.println();
					flag = arr[i + 1];
				}
			}
			else
			{
				if (arr[i] == arr[i-1] + 1)
				{
					System.out.println();
				}
				else
				{
					System.out.print(arr[i]);
					System.out.print('-');
					System.out.println(arr[i]);
				}
			}
			
		}
	}

 * ********************************************************************/
