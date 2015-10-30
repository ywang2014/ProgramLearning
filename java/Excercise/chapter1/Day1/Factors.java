package Day1;

public class Factors
{
	//takes a command-line argument N and prints its prime factorization
	public static void main(String[] args)
	{
		int n = Integer.parseInt(args[0]);
		
		System.out.print(n + " prime factors:");
		for (int i = 2; i <= n; i++)
		{
			if ((n % i == 0) && prime(i))
			{
				System.out.print(" " + i);
			}
		}
		System.out.println(" ");	// »»ÐÐ
	}
	
	public static boolean prime(int n)
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}
