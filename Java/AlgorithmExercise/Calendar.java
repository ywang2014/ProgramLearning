/*
 * 	输出日历 ：1900年以后的任意时期的月日历。
 * 
 * 写完的java 源代码 用eclipse 生成可以运行的软件
 * 将其导出为jar文件：右击要导出的文件-export-jar file
 * 注意一定要选择Main class最后生成.jar文件,
 * 运行时使用命令：java -jar xxx.jar
 * 或者创建一个bat文件搜索，将上面的命令写入其中，
 * 双击.bat文件执行jar命令即可
 *  代码中右键->运行->Java应用程序，程序运行了，
 *  对应的目录下面会生成后缀为class的文件，
 *  只要有Jre的地方都可以运行class。
 *   如果要变为exe的话，
 *   下载exe4j来生成exe文件也可以。
 */

import java.util.*;
public class Calendar {
	private final int epochYear = 1900;
	private final int[] monthDays = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	private int year;
	private int month;
	
	public void getInputData(){
		Scanner input = new Scanner(System.in);
		System.out.println("请输入年份：(年份为从1900年开始的任意年份时间，必须是整数。如：2018)");
		this.year = input.nextInt();
		while (!checkYear()){
			System.out.println("对不起，您输入的年份非法，请再次输入你想查询的年份，谢谢！");
			System.out.println("请输入年份：");
			this.year = input.nextInt();
		}
		System.out.println("请输入月份：(月份为1,2,...,12中的任意月份。如：12)");
		this.month = input.nextInt();
		while (! checkMonth()){
			System.out.println("对不起，您输入的月份非法，请再次输入你想查询的月份，谢谢！");
			System.out.println("请输入月份：");
			this.month = input.nextInt();
		}
	}
	
	private boolean checkYear(){
		return this.year >= this.epochYear;
	}
	
	private boolean checkMonth(){
		return 1 <= this.month && this.month <= 12;
	}
	
	public long calculateDays(){
		long days = 0;
		for (int i = epochYear; i < year; i++){
			days += 365;
			if (((i%4 == 0) && (i%100 != 0)) || (i%400 == 0)){
				days += 1;
			}
		}
		for (int i = 1; i < month; i++){
			days += getMonthDays(i, year);
		}
		return days;
	}
	
	private int getMonthDays(int monthNum, int yearNum){
		if (monthNum == 2 && (((yearNum%4 == 0) && (yearNum%100 != 0)) || (yearNum%400 == 0))){
			return monthDays[0];
		}
		return monthDays[monthNum];
	}
	
	public void printCalendar(long days){
		// 打印日历星期头
		System.out.println("日\t一\t二\t三\t四\t五\t六");
		// 定位1号在本月中的星期位置
		long offsetDay = days % 7;
		for (int i = 0; i <= offsetDay; i++){
			System.out.print("\t");
		}
		System.out.print("1\t");
		
		// 打印本月的其他日期：依次按照1号日期顺序打印即可
		int monthdays = getMonthDays(month, year);
		for (int i = 2; i <= monthdays; i++){
			if((offsetDay + i - 1) % 7 == 6){
				System.out.println();
			}
			System.out.print(i+"\t");
		}
	}
	
	public static void calendarManager(){
		System.out.println("Welcome to my calendar app.");
		Calendar calendar = new Calendar();
		Scanner in = new Scanner(System.in);
		int command = 1;
		while (command == 1){
			calendar.getInputData();
			calendar.printCalendar(calendar.calculateDays());
			System.out.println("\n\n\nContinue to use calendar app? (1/0)");
			command = in.nextInt();
		}
	}
	
	public static void main(String[] args){
		Calendar.calendarManager();
	}
	
	
	
	/*********** version 0.1  ***********/
	private void calendar_01(){
		int sum = 0;
		int i;
		Scanner input = new Scanner(System.in);
		System.out.println("请输入年份：");
		int year = input.nextInt();
		System.out.println("请输入月份：");
		int month = input.nextInt();
		for (i=1900; i<year; i++)
		{
			if (((i%4 == 0) && (i%100 != 0)) || (i%400 == 0))
			{
				sum += 366;
			}
			else
			{
				sum += 365;
			}
		}
		/*
		switch (month)
		{
		case 1: 
		{
			if (month == 1)
			{
				break;
			}
			else
			{
				sum += 31;
			}
		}
		case 2:
		{
			if (month == 2)
			{
				break;
			}
			else
			{
				if(((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
				{
					sum += 29;
				}
				else 
				{
					sum += 28;
				}
				
			}
		}
		case 3:
		{
			if (month == 3)
			{
				break;
			}
			else
			{
				sum += 31;
			}
		}
		case 4:
		{
			if (month == 4)
			{
				break;
			}
			else
			{
				sum += 30;
			}
		}
		case 5:
		{
			if (month == 5)
			{
				break;
			}
			else
			{
				sum += 31;
			}
		}
		case 6:
		{
			if (month == 6)
			{
				break;
			}
			else
			{
				sum += 30;
			}
		}
		}
		*/
		for (i=1; i<month; i++)
		{
			if (i == 2)
			{
				if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
				{
					sum += 29;
				}
				else
				{
					sum += 28;
				}
			}
			else 
			{
				if ((i == 4) || (i == 6) || (i == 9) || (i == 11))
				{
					sum += 30;
				}
				else 
				{
					sum += 31;
				}
			}
		}
		sum++;   //1号，多加一天。
		int weekday = sum%7;
		System.out.println("日\t一\t二\t三\t四\t五\t六");
		for (i=0; i<weekday; i++)
		{
			System.out.print("\t");
		}
		System.out.print("1\t");
		int monthdays;
		if (month == 2)
		{
			if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
			{
				monthdays = 29;
			}
			else
			{
				monthdays = 28;
			}
		}
		else 
		{
			if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
			{
				monthdays = 30;
			}
			else 
			{
				monthdays = 31;
			}
		}
		for (i=2; i<=monthdays; i++)
		{
			if(sum%7 == 6)
			{
				System.out.println();
			}
			System.out.print(i+"\t");
			sum++;
		}
	}
}
