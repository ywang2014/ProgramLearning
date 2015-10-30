/*
 * 360 面试题目1：
 * 		计算器增加新功能，输出任意数的“素数公因子” 2,3,5,7...
 * 		输出特殊字符，如图 ：5*3 
 **************
 -   
| |

| |
 - 
**************

 |

 |

**************
 - 
  |
 -
| 
 - 
**************

| |
 - 
  |
  
**************
 - 
| 
 - 
  |
 - 
**************
 -
|
 -
| |
 - 
**************
 - 
  |
 
  |
 
**************
 -
| |
 -
| |
 _ 
**************
 -
| |
 -
  |
 - 
**************
 * 		输入： 66
 * 		输出： * 两边各一个空格
 -     -
  |     |    |   |
 -  *  -  *   
|       |    |   |
 -     -
 
 思路：
 	第一步：求出所有的  prime factor	(需要存储)
 	第二步：解析素数因子：多位数分解成为一位一位的 eg:17 = 1 7	(需要存储)
 		解析需要先求最高位，
 		while(i < n)
		{
			i *= 10;
		}
		while(n >= 0)
		{
			i /= 10;
			remainder = n / i;
			n = n - i * remainder;
		}

 	第三步：一行一行输出：因数之间加三个空格，第三行加  “*”
 	实现：将数字存储在矩阵之中，方便解析
 */

package Day1;

import java.util.Scanner;

public class Test360
{                      
	char gui[ ][  ] = {{' ','-',' ',  ' ',' ',' ',  ' ','-',' ',  ' ','-',' ',  ' ',' ',' ',  ' ','-',' ',  ' ','-',' ',  ' ','-',' ',  ' ','-',' ',  ' ','-',' '},
			     	   {'|',' ','|',  ' ','|',' ',  ' ',' ','|',  ' ',' ','|',  '|',' ','|',  '|',' ',' ',  '|',' ',' ',  ' ',' ','|',  '|',' ','|',  '|',' ','|'},
			     	   {' ',' ',' ',  ' ',' ',' ',  ' ','-',' ',  ' ','-',' ',  ' ','-',' ',  ' ','-',' ',  ' ','-',' ',  ' ',' ',' ',  ' ','-',' ',  ' ','-',' '},
			     	   {'|',' ','|',  ' ','|',' ',  '|',' ',' ',  ' ',' ','|',  ' ',' ','|',  ' ',' ','|',  '|',' ','|',  ' ',' ','|',  '|',' ','|',  ' ',' ','|'},
			     	   {' ','-',' ',  ' ',' ',' ',  ' ','-',' ',  ' ','-',' ',  ' ',' ',' ',  ' ','-',' ',  ' ','_',' ',  ' ',' ',' ',  ' ','-',' ',  ' ','-',' '}};
/*	                    
 * 0:(0-2)	1:(3-5)	2:(6-8)	3:(9-11)	n:(3n-3n+2)
 * 在字符串中，查找对应的数字，一行一行输出：解析出素数，每个数字再解析！
 */
	
 	public void myPrint(int n)
	{
 		int i = 1;
 		System.out.println("逆序输出");
		while (n > 0)
		{
			System.out.println("第 " + i + " :");
			myPrintGUI(n % 10);
			i++;
			n /= 10;
		}
	}
	
 	public void myPrintGUI(int n)
	{
		switch (n)
		{
			case 0:print0();break;
			case 1:print1();break;
			case 2:print2();break;
			case 3:print3();break;
			case 4:print4();break;
			case 5:print5();break;
			case 6:print6();break;
			case 7:print7();break;
			case 8:print8();break;
			case 9:print9();break;
			default: break;
		}
	}
	
 	// 此种输出不行，不能输出在一起！
	public void print0()
	{
		System.out.println(" - ");
		System.out.println("| |");
		System.out.println("   ");
		System.out.println("| |");
		System.out.println(" - ");
	}

	public void print1()
	{
		System.out.println("   ");
		System.out.println(" | ");
		System.out.println("   ");
		System.out.println(" | ");
		System.out.println("   ");
	}

	public void print2()
	{
		System.out.println(" - ");
		System.out.println("  |");
		System.out.println(" - ");
		System.out.println("|  ");
		System.out.println(" - ");
	}

	public void print3()
	{
		System.out.println(" - ");
		System.out.println("  |");
		System.out.println(" - ");
		System.out.println("  |");
		System.out.println(" - ");
	}

	public void print4()
	{ 
		System.out.println("   ");
		System.out.println("| |");
		System.out.println(" - ");
		System.out.println("  |");
		System.out.println("   ");
	}

	public void print5()
	{
		System.out.println(" - ");
		System.out.println("|  ");
		System.out.println(" - ");
		System.out.println("  |");
		System.out.println(" - ");
	}

	public void print6()
	{
		System.out.println(" - ");
		System.out.println("|  ");
		System.out.println(" - ");
		System.out.println("| |");
		System.out.println(" - ");
	}

	public void print7()
	{
		System.out.println(" - ");
		System.out.println("  |");
		System.out.println("   ");
		System.out.println("  |");
		System.out.println("   ");
	}
	
	public void print8()
	{
		System.out.println(" - ");
		System.out.println("| |");
		System.out.println(" - ");
		System.out.println("| |");
		System.out.println(" - ");
	}
	
	public void print9()
	{
		System.out.println(" - ");
		System.out.println("| |");
		System.out.println(" -  ");
		System.out.println("  |");
		System.out.println(" - ");
	}
	
	
	public void factor(int n)
	{
		System.out.println("The factors is :");
		for (int i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				while (n % i == 0)
				{
					n /= i;
				}
				myPrint(i);
				System.out.println("");
			}
		}
	}
	public static void main(String[] args)
	{
		Test360 obj = new Test360();
		
		System.out.println("Please input a number:");
		
		Scanner input = new Scanner(System.in);
		int n;
		if(input.hasNext())
			n = (int) input.nextInt();
		else 
			n=0;
		
		input.close();
		obj.factor(n);
	}
}




 

  


