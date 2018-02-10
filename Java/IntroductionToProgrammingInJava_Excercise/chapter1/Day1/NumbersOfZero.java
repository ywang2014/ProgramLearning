package Day1;

import java.util.Scanner;

public class NumbersOfZero
{
	public static void main(String[] args)
	{
		int n = 0;
		int m = 0;
		int count = 0;	// 总共0的个数
		
		Scanner input = new Scanner(System.in);
		m = (int) input.nextInt();
		n = (int) input.nextInt();
		
		for (int i = m; i <= n; i++)
		{
			int j = i;
			if (j == 0)
			{
				count++;
			}
			else
			{
				while(j != 0)
				{
					if (j % 10 == 0)
					{
						count++;
					}
					j /= 10;
				}
			}
		}
		
		System.out.println(count);
		input.close();
	}
}
