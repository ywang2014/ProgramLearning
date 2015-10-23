package Day1;

public class Gambler
{
	public static void main(String[] args)
	{
		int stake = Integer.parseInt(args[0]);
		int amount = Integer.parseInt(args[1]);
		int times = Integer.parseInt(args[2]);
		int wins = 0;
		int ruins = 0;
		
		for (int i = 0; i < times; i++)	// 保持times不变化，用于输出
		{
			int money = stake;
			while (money > 0 && money < amount)
			{
				if ((int)(Math.random() * 10) % 2 == 0)
				{
					money++;
				}
				else
				{
					money--;
				}
			}
			if (money == 0)
			{
				ruins++;
			}
			else
			{
				wins++;
			}
		}
		System.out.println("Wins: " + wins);
		System.out.println("Ruins: " + ruins);
	}
}
