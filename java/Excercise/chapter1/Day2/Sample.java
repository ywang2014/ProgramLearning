/**********************************************************
 *  Compilation:	javac Sample.java
 *  Execution:		java Sample N M
 *  This program takes two command-line arguments M and N and produces
 *  a random sample of M of the integers from 0 to N-1.
 *  
 **********************************************************/

package Day2;

public class Sample
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		int M = Integer.parseInt(args[1]);
		
		// create permutation 0, 1, ..., N-1
		int permutation[] = new int[N];
		for (int i = 0; i < N; i++)
		{
			permutation[i] = i;
		}
		
		// create random sample in permutation[0 ~ M-1]
		for (int i = 0; i < M; i++)
		{
			// create random integer between i and N-1
			int rand = (int)(Math.random() * (N - i)) + i;
			
			// swap the elements at indices i and rand
			int temp = permutation[rand];
			permutation[rand] = permutation[i];
			permutation[i] = temp;
		}
		
		// print the results
		for (int i = 0; i < M; i++)
		{
			System.out.print(permutation[i] + " ");
		}
		System.out.println();
	}
}
