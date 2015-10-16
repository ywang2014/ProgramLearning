/******************************************************************************
 *  Compilation:  javac StdIn.java
 *  Execution:    java StdIn   (interactive test of basic functionality)
 *  Dependencies: none
 *
 *  Reads in data of various types from standard input.
 *
 ******************************************************************************/
package Day2.IO;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.regex.Pattern;

public final class StdIn
{
	/*** begin: section (1 of 2) of code duplicated from In to StdIn. */
	
	// assume Unicode UTF-8 encoding
	private static final String CHARSET_NAME = "UTF-8";
	
	// assume language = English, country = China for consistency with System.out.
	private static final Locale LOCALE = Locale.CHINA;
	
	// the default token separator; we maintain the invariant that this value
	// is held by the scanner's delimiter between calls
	private static final Pattern WHITESPACE_PATTERN = Pattern.compile("\\p{javaWhitespace}+");
	
	// 使得空白符有意义
	private static final Pattern EMPTY_PATTERN = Pattern.compile("");
	
	// 用于读取整个输入
	private static final Pattern EVERYTHING_PATTERN = Pattern.compile("\\A");
	
	/*** 结束： 代码的1/2部分从In复制到StdIn */
	
	private static Scanner scanner;
	
	// 实例化这个类是没有意义的
	private StdIn(){}
	
	//// 开始：代码的 2/2部分从In复制到StdIn，将所有的公有方法改成公有静态方法
	
	// 如果标准输入为空(除了少数可能就是输入空字符)，则返回真
	public static boolean isEmpty()
	{
		return !scanner.hasNext();
	}
	
	// 如果标准输入有下一行，则返回真
	public static boolean hasNextLine()
	{
		return scanner.hasNextLine();
	}
	
	// 如果标准输入中还有字符，则返回真
	public static boolean hasNextCahr()
	{
		// 设置scanner的定界符
		scanner.useDelimiter(EMPTY_PATTERN);
		boolean result = scanner.hasNext();
		scanner.useDelimiter(WHITESPACE_PATTERN);
		return result;
	}
	
	// 读取并返回下一行， 不包括行分隔符(如果有，则删除)
	public static String readLine()
	{
		String line;
		try
		{
			line = scanner.nextLine();
		}
		catch (NoSuchElementException e)
		{
			line = null;
		}
		return line;
	}
	
	// 读取并返回下一个字符
	public static char readChar()
	{
		scanner.useDelimiter(EMPTY_PATTERN);
		String ch = scanner.next();
		assert ch.length() == 1 : "Internal (Std)In.readChar() error!"
			+ " Please contact the authors.";
		scanner.useDelimiter(WHITESPACE_PATTERN);
		return ch.charAt(0);
	}
	
	// 读取并以一个字符串的形式返回所有的输入
	public static String readAll()
	{
		if (!scanner.hasNextLine())
		{
			return "";
		}
		String result = scanner.useDelimiter(EVERYTHING_PATTERN).next();
		// 现在scanner是空的，所以说复位定界符不是很重要，但是无论如何还是复位一下。
		scanner.useDelimiter(WHITESPACE_PATTERN);
		return result;
	}
	
	// 读取下一个字符串并返回这个字符串
	public static String readString()
	{
		return scanner.next();
	}
	
	// 从标准输入读取下一个标记类型，语法上分析其为一个整形数，并返回它
	public static int  readInt()
	{
		return scanner.nextInt();
	}
	
	// 从标准输入读取下一个标记类型，语法上分析其为一个长精度类型，并返回它
	public static double  readDouble()
	{
		return scanner.nextDouble();
	}
	
	// 从标准输入读取下一个标记类型，语法上分析其为一个浮点类型，并返回它
	public static float  readFloat()
	{
		return scanner.nextFloat();
	}
	
	// 从标准输入读取下一个标记类型，语法上分析其为一个长整形，并返回这个长整形
	public static long  readLong()
	{
		return scanner.nextLong();
	}
	
	// 从标准输入读取下一个标记类型，语法上分析其为一个短整形，并返回它
	public static short  readShort()
	{
		return scanner.nextShort();
	}
	
	// 从标准输入读一个字节，并返回它
	public static byte readByte()
	{
		return scanner.nextByte();
	}
	
	// 从标准输入读一个布尔类型值，然后返回它
	public static boolean readBoolean()
	{
		String s = readString();
		if (s.equalsIgnoreCase("true"))
		{
			return true;
		}
		else if (s.equalsIgnoreCase("false"))
		{
			return false;
		}
		else if (s.equals("1"))
		{
			return true;
		}
		else if (s.equals("0"))
		{
			return false;
		}
		throw new InputMismatchException();
	}
	
	// 从标准输入读取所有可能的类型值，使用一个字符串数组返回它们
	public static String[] readAllStrings()
	{
		// 我们可以使用 readAll.trim().split() 方法，但是不能保持一致性，因为 trim() 方法使用 0x00,0x20作为空白符
		String[] tokens = WHITESPACE_PATTERN.split(readAll());
		if (tokens.length == 0 || tokens[0].length() > 0)
		{
			return tokens;
		}
		
		// 如果是以空字符开头的，不包括第一个标记
		String[] decapitokens = new String[tokens.length - 1];
		for (int i = 0; i < tokens.length - 1; i++)
		{
			decapitokens[i] = tokens[i+1];
		}
		return decapitokens;
	}
	
	// 从标准输入中，读取所有行，以字符串数组的形式返回它们
	public static String[] readAllLines()
	{
		ArrayList<String> lines = new ArrayList<String>();
		while (hasNextLine())
		{
			lines.add(readLine());
		}
		
		return lines.toArray(new String[0]);
	}
	
	// 读取并返回所有的整数
	public static int[] readAllInts()
	{
		String[] fields = readAllStrings();
		int [] vals = new int[fields.length];
		for (int i = 0; i < fields.length; i++)
		{
			vals[i] = Integer.parseInt(fields[i]);
		}
		return vals;
	}
	
	// 读取并返回所有的双精度浮点数
	public static double[] readAllDoubles()
	{
		String[] fields = readAllStrings();
		double [] vals = new double[fields.length];
		for (int i = 0; i < fields.length; i++)
		{
			vals[i] = Double.parseDouble(fields[i]);
		}
		return vals;
	}
	
	//// 结束： 代码的(2/2)部分从In复制到StdIn
	
	// 当StdIn被初始化的时候，执行一次下面代码
	static
	{
		resync();
	}
	
	// 如果StdIn发生改变，使用这个函数初始化scanner
	private static void resync()
	{
		setScanner(new Scanner(new java.io.BufferedInputStream(System.in), CHARSET_NAME));
	}
	
	private static void setScanner(Scanner scanner)
	{
		StdIn.scanner = scanner;
		StdIn.scanner.useLocale(LOCALE);
	}
	
	// 读取所有整数
	public static int[] readInts()
	{
		return readAllInts();
	}
	
	// 读取所有的双精度浮点数
	public static double[] readDoubles()
	{
		return readAllDoubles();
	}
	
	// 读取所有字符串
	public static String[] readStrings()
	{
		return readAllStrings();
	}
	
	// 交互的方式测这些基本函数
	public static void main(String[] args)
	{
		// StdOut.print("Type a string:");
		System.out.print("Type a string:");
		String s = StdIn.readString();
		System.out.println("Your string was: " + s);
		
		
		System.out.print("Type a int:");
		int a = StdIn.readInt();
		System.out.println("Your int was: " + a);
		
	}
}
