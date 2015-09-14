package Day1;

public class Harmonic
{
	public static void main(String[] args)
	{
		int n = Integer.parseInt(args[0]);
		
		if (n < 1)
		{
			System.out.println("Parameter error!");
			return ;
		}
		int i = 1;
		double harSum = 0;
		while (i <= n)
		{
			harSum += 1.0 / i;
			i++;
		}
		System.out.print(n + " harSum = ");
		System.out.println(harSum);
	}
}
