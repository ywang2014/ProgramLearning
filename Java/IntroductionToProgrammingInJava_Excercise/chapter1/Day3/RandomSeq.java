/**
 * It takes a command-line argument N and 
 * produces an output sequence of random numbers between 0 and 1.
 */

package Day3;

public class RandomSeq
{
	public static void main(String[] args)
	{
		// command-line argument
		int N = Integer.parseInt(args[0]);
		for (int i = 0; i < N; i++)
		{
			System.out.println(Math.random());
		}
	}
}
