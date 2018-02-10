package Day1;

import java.util.Scanner;

public class Graduate
{
	float polic;
	float english;
	float math;
	float computer;
	
	
	public void judge()
	{
		float amount= polic + english + math + computer;
				
		if (amount < 310)
		{
			System.out.println("fail");
		}
		else if (polic >= 60 && english >= 60 && math >= 90 && computer >= 0)
		{
			if (amount >= 350)
			{
				System.out.println("Gongfei");
			}
			else
			{
				System.out.println("Zifei");
			}
		}
		else
		{
			System.out.println("fail");
		}
	}
	
	public static void main(String[] args)
	{
		Graduate stu1 = new Graduate();
		
		System.out.println("Please input the grades:");
		
		Scanner input = new Scanner(System.in);
		stu1.polic = input.nextInt();
		stu1.english = input.nextInt();
		stu1.math = input.nextInt();
		stu1.computer = input.nextInt();
		
		input.close();
		
		stu1.judge();
	}

}
