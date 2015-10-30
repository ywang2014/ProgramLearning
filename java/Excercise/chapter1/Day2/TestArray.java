package Day2;

public class TestArray
{
	public static void main(String[] args)
	{
		/* poker */
		String[] suit = {"Clubs", "Diamonds", "Hearts", "Spades"};	// Ã·»¨¡¢·½¿é¡¢ºìÌÒ¡¢ºÚÌÒ
		String[] rank = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
				"Jack", "Queen", "King", "Ace"
		};
		
		int i = (int) (Math.random() * rank.length);
		int j = (int) (Math.random() * suit.length);
		
		System.out.println(rank[i] + " of " + suit[j]);
		
		String[] deck = new String[rank.length * suit.length];
		for (int k = 0; k < suit.length; k++)
		{
			for (int t = 0; t < rank.length; t++)
			{
				deck[rank.length * k + t] = rank[t] + " of " + suit[k];
			}
		}
		// System.out.println(rank[t] + " of " + suit[k]);
		
		// shuffling
		int N = deck.length;
		for (int k = 0; k < N; k++)
		{
			int r = k + (int)(Math.random() * (N - k));
			String temp = deck[r];
			deck[r] = deck[k];
			deck[k] = temp;
		}
		
		// print deck
		for (int k = 0; k < N; k++)
		{
			System.out.println(deck[k]);
		}
		
		// calculate the harmonic numbers
		double[] har = new double[N];
		for (int k = 1; k < N; k++)
		{
			har[k] = har[k-1] + 1.0 / k;
		}
		
		System.out.println(har[(int)(Math.random() * N)]);
	}
}