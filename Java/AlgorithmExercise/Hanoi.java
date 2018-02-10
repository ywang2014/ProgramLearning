/**
    * @date 20150630
    * @author ywang
    * @http http://baike.baidu.com/view/191666.htm
    * @param n 层数
    * @param A B C 三根柱子名称
    * 
    */

package com.classicalproblem;

public class Hanoi 
{
	/*
	int n;	//汉诺塔层数
	
	public Hanoi(int n)
	{
		this.n = n;
	}*/
	public void hanoi(int n, char A, char B, char C)
	{
		if (n == 1)
		{
			System.out.println("Move: " + A + " --> " + C);
		}
		else
		{
			hanoi(n-1, A, C, B);
			System.out.println("Move: " + A + " --> " + C);
			hanoi(n-1, B, A, C);
		}
	}
	public static void main(String[] args)
	{
		//Hanoi hanoi = new Hanoi(1);
		//hanoi.hanoi('A', 'B', 'C');
		Hanoi hanoi2 = new Hanoi();
		hanoi2.hanoi(3, 'A', 'B', 'C');
	}
}
