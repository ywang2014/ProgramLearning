package Day2;

public class CouponCollector
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		
		boolean[] flag = new boolean[N];
		for (int i = 0; i < N; i++)
		{
			flag[i] = false;
		}
		
		int couponcnt = 0;
		int valcnt = 0;
		
		while (valcnt < N)
		{
			int val = (int) (Math.random() * N);	// random card between 0 and N-1
			couponcnt++;							// we have collected total of card
			if (! flag[val])
			{
				valcnt++;							// a new card
				flag[val] = true;					// indicate that we have collected the card.
			}
		}
		
		System.out.println("The total of cards = " + couponcnt);
	}
}
