package Day3.pagerank;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Transition
{
	public static void main(String[] args)
	{
		InputStream in = null;
		OutputStream out = null;
		try
		{
			in = new FileInputStream(new File("./src/Day3/pagerank/tiny.txt")); // ../workspace/Exercise/src/Day3/pagerank/tiny.txt
			out = new FileOutputStream(new File("src/Day3/pagerank/probability.txt"));
		} catch (FileNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Scanner sc = new Scanner(in);
		PrintStream ps = new PrintStream(out);
		
		int N = sc.nextInt();	// number of pages
		int [][] transitionMatrix = new int[N][N];	// links
		int [] outDegree = new int[N];	// degrees
		
		while (sc.hasNext())
		{
			int i = sc.nextInt();
			int j = sc.nextInt();
			transitionMatrix[i][j]++;
			outDegree[i]++;
		}
		
		System.out.println(N + " " + N);
		ps.println(N + " " + N);
		
		// Print probability distribution for row i
		for (int i = 0; i < N; i++)
		{
			// Print probability for column j.
			for (int j = 0; j < N; j++)
			{
				double p = 0.9 * transitionMatrix[i][j] / outDegree[i] + 0.1 / N;
				System.out.printf("%7.5f ", p);
				ps.printf("%7.5f ", p);
			}
			System.out.println();
			ps.println();
		}
		
		sc.close();
		ps.close();
	}
}
