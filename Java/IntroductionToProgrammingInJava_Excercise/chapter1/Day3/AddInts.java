/**
 * takes an argument N from the command line, then reads N numbers from standard input and adds them:
 */

package Day3;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Scanner;

import Day2.IO.StdIn;
import Day2.IO.StdOut;

public class AddInts
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		long sum = 0;
		System.out.println("Please input " + String.valueOf(N) + " numbers: ");
		for (int i = 0; i < N; i++)
		{
			sum += StdIn.readInt();
		}
		StdOut.println(sum);
		
		// 逐行扫描文件，并输出
		InputStream in = null;
		try
		{
			in = new FileInputStream(new File("./src/Day3/0.jpg"));
		} catch (FileNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Scanner s = new Scanner(in);	// Scanner(System.in)
		while(s.hasNextLine())
		{
			System.out.println(s.nextLine());
		}
		s.close();
	}
}
