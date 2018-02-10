/******************************************************************************
 *  Compilation:  javac Shuffle.java
 *  Execution:    java Shuffle arg1 arg2 arg3
 *  
 *  Prints out the command line arguments in random order.
 *  Uses a function that takes an array and rearranges it 
 *  in random order.
 *
 *  % java Shuffle Alice Bob Cynthia Dan Erin Frank
 *  Bob
 *  Frank
 *  Dan
 *  Cynthia
 *  Alice
 *  Erin
 *
 *  % java Shuffle Alice Bob Cynthia Dan Erin Frank
 *  Cynthia
 *  Alice
 *  Frank
 *  Dan
 *  Erin
 *  Bob
 *
 ******************************************************************************/

package chapter2.day1;

public class Shuffle
{
	// swaps array elements by index
	public static void exchange(String[] arr, int i, int j)
	{
		String temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	// take as input an array of strings and rearrange them in random order
	public static void shuffle(String[] arr)
	{
		int N = arr.length;
		for (int i = 0; i < N; i++)
		{
			int r = i + (int)(Math.random() * (N - i));	// index between i and N-1
			exchange(arr, i, r);
		}
	}
	
	// take as input an array of strings and print them out to standard output
	public static void show(String[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out.println(arr[i]);
		}
	}
	
	// shuffle the command line arguments
	public static void main(String[] args)
	{
		show(args);
		
		shuffle(args);
		
		System.out.println("\n****************** After shuffling **************\n");
		show(args);
	}
}
