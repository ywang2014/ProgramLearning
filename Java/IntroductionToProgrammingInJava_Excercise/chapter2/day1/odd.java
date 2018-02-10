/*****************************************************
 * 
 * Write a static method odd() that takes sequence boolean inputs
 * returns true if an odd number of inputs are true, and false otherwise.
 * 
 ******************************************************/

package chapter2.day1;

public class odd
{
	public static boolean isOdd1(boolean[] args)
	{
		int count = 0;
		for (int i = 0; i < args.length; i++)
		{
			if (args[i])
			{
				count++;
			}
		}
		if (count % 2 == 1)
		{
			return true;
		}
		return false;
	}
	
	public static boolean isOdd2(boolean[] args)
	{
		int count = 0;
		for (int i = 0; i < args.length; i++)
		{
			//count += (int)args[i]; // java Cannot cast from boolean to int
			count += args[i] ? 1 : 0;
		}
		
		return count % 2 == 1;
	}
	
	public static boolean isOdd3(boolean[] args)
	{
		boolean result1 = false;
		boolean result2 = false;
		for (int i = 0; i < args.length; i++)
		{
			// Âß¼­´íÎó£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
			result1 = args[i] && result1 ? !args[i] : args[i];
			result2 = args[i] || result2 ? !args[i] : args[i];
		}
		
		return result1;
	}
	
	/****************************************************************
	 * Write a static method majority() that takes three boolean arguments 
	 * returns true if at least two of the arguments have the value true, and false otherwise. 
	 * Do not use an if statement. 
	 * Solution: here are two solutions: 
	 * 		the first is concise; 
	 * 		the second strictly adheres to the rules.
	 * 
	 */
	public static boolean majority(boolean a, boolean b, boolean c) 
	{
	   return (a && b) || (a && c) || (b && c);
	}

	public static boolean majority2(boolean a, boolean b, boolean c) 
	{
	   while (a && b) return true;
	   while (a && c) return true;
	   while (b && c) return true;
	   return false;
	}
	
	
	public static void main(String[] args)
	{
		boolean[] arr = {true, false, true, false};
		/*
		for (int i = 0; i < args.length; i++)
		{
			arr[i] = (boolean)args[i];
		}
		*/
		if (isOdd3(arr))
		{
			System.out.println("odd");
		}
		else
		{
			System.out.println("even");
		}
	}
}
