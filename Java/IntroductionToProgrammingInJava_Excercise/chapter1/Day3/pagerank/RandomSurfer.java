package Day3.pagerank;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Scanner;

public class RandomSurfer
{
	@SuppressWarnings("resource")
	public static void main(String[] args)
	{
		int T = Integer.parseInt(args[0]);	// number of moves 1000000
		InputStream in = null;
		try
		{
			in = new FileInputStream(new File("src/Day3/pagerank/probability.txt"));
		}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
		Scanner input = new Scanner(in);
		int M = input.nextInt();
		int N = input.nextInt();
		if (M != N) throw new RuntimeException("M does not equal N");
		
		double[][] p = new double[M][N]; // p[i][j] = prob. that surfer moves from page i to page j
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				p[i][j] = input.nextDouble();
			}
		}
		
		int[] frequence = new int[N];	// freq[i] = times surfer hits page i.
		// start at page 0
		int page = 0;
		
		for (int i = 0; i < T; i++)
		{
			// make one random move
			double r = Math.random();
			double sum = 0.0;
			for (int j = 0; j < N; j++)
			{
				// find interval containing r
				sum += p[page][j];	// 概率和
				if (r < sum)	// 如果r小于当前概率和，则跳转成功
				{
					page = j;	// 调到 page j 网页
					break;
				}
			}
			frequence[page]++;
		}
		
		// Print page ranks.
		for (int i = 0; i < N; i++)
		{
			System.out.printf("%8.5f ", (double) frequence[i] / T);
		}
		System.out.println();
		
		input.close();
	}
}

/******************************************************************************
 * Below is the syntax highlighted version of RandomSurfer.java from §2.2 Libraries. 
 *
 *  Compilation:  javac RandomSurfer.java
 *  Execution:    java RandomSurfer N
 *
 *  % java Transition < tinyGraph.txt | java RandomSurfer 1000000
 *   0.27297 0.26583 0.14598 0.24729 0.06793
 *
 ******************************************************************************

public class RandomSurfer {
    public static void main(String[] args) {

        // number of moves
        int T = Integer.parseInt(args[0]);

        // Transition matrix: p[i][j] = prob. that surfer moves from page i to 
        double[][] p = StdArrayIO.readDouble2D();

        // dimension of the transition matrix
        int N = p.length;

        // freq[i] = # times surfer hits page i
        int[] freq = new int[N];
 
        // simulate the random surfer, starting at a random state
        int state = StdRandom.uniform(N);
        for (int t = 0; t < T; t++) {
            state = StdRandom.discrete(p[state]);
            freq[state]++;
        }

        // Print page ranks. 
        for (int i = 0; i < N; i++) {
            StdOut.printf("%8.5f", (double) freq[i] / T); 
        }
        StdOut.println(); 
    }  
} 

 ******************************************************************************/