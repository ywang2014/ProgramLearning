package Day1;

public class RulerN
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		// ruler of order 0
		String ruler = " ";
		
		// repeat N times;
		for (int i = 1; i <= N; i++)
		{
			// concatenate a ruler of order 0, the number i, and the ruler
			ruler = ruler + i + ruler;
			
			// print out the final result
			System.out.println(ruler);
		}
	}
}

/*
 1 
 1 2 1 
 1 2 1 3 1 2 1 
 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 
 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
 */
