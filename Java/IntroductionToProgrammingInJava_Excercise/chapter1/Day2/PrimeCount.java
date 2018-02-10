package Day2;

public class PrimeCount
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		
		// 节省空间  boolean int 
		char primeSieve[] = new char[N+1];
		for (int i = 2; i <= N; i++)
		{
			primeSieve[i] = '1';
		}
		
		for (int i = 2; i*i <= N; i++)
		{
			if (primeSieve[i] == '1')
			{
				/*
				int j = 2 * i;
				while (j <= N)
				{
					primeSieve[j] = '0';
					j += i;
				}*/
				for (int j = i; i * j <= N; j++)
				{
					// i*i 开始的逻辑是正确的!!!! 因为小于 i*i的都考虑了。比如 2i,3i and so forth 由2的倍数，3的倍数etc考虑的。
					primeSieve[i*j] = '0';
				}
			}
		}
		
		int count = 0;
		for (int i = 2; i <=N; i++)
		{
			if (primeSieve[i] == '1')
			{
				count++;
			}
		}
		System.out.println("Counts of prime <= " + N + " is " + count);
	}
	
}
