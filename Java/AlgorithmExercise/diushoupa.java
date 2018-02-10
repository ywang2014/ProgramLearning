/*
 * author : ywang
 * function: 删除第m个数。
 * date :2015/1/19
 * *************************************
 * 练习纯面向对象
 */

package com.ywang;

public class diushoupa
{
	public static void main(String[] args)
	{
		CycLink mylink = new CycLink();
		mylink.setK(5);
		mylink.setM(7);
		mylink.printLink();
		Child first = mylink.first();
		while (!mylink.empty()){
			first = mylink.play(first);
		}
	}
}

class Child
{
	int data;
	Child next = null;
	
	public Child(int data)
	{
		this.data = data;	//编号
	}
}

class CycLink
{
	//先定义指向第一个小孩的引用
	Child firstChild = null;  //指向第一个小孩的引用不能改变。
	Child index = null;  //游标，索引
	int length = 0;    //小孩总数
	int k = 0;
	int m = 0;
	
	public CycLink(int l){
		this.length = l;
		createLink();
	}
	
	public CycLink(){
		this.length = 16;
		createLink();
	}
	
	public void setLength(int length)
	{
		this.length = length;
	}
	
	public boolean empty(){
		return length == 0;
	}
	
	//设置开始数的小孩编号
	public void setK(int k)
	{
		this.k = k;
	}
	
	//设置m，删除第m号小孩
	public void setM(int m)
	{
		this.m = m;
	}
	
	public Child first(){
		return firstChild;
	}
	
	public Child play(Child first)
	{
		Child temp = first;
		//找到第m个小孩
		for ( int i=1; i<k; i++)
		{
			temp = temp.next;
		}
		//删除第m个小孩
		for (int j=1; j<m-1;j++)
		{
			temp = temp.next;
		}
		Child del = temp.next;
		System.out.println(del.data);
		temp = del.next;//覆盖了中间的temp.next
		this.length--;
		
		return temp;
	}
	
	
	//初始化环形链表
	public void createLink()
	{
		for (int i=1; i<=length; i++)
		{
			if (i==1)
			{
				//创建第一个小孩
				Child ch = new Child(i);
				this.firstChild = ch;
				this.index = firstChild;
			}
			else 
			{
				if (i == length)
				{
					Child ch = new Child(i);
					index.next = ch;
					index = ch;
					index.next = this.firstChild;	
				}
				else
				{
					Child ch = new Child(i);
					index.next = ch;
					index = ch;
				}
			}
		}
	}
	
	//打印
	public void printLink()
	{
		//定义游标
		Child temp = this.firstChild;
		do
		{
			if (temp == null){
				System.out.println("No");
				break;
			}
			System.out.println(temp.data);
			temp = temp.next;
		}while (temp != this.firstChild);
		System.out.println();
	}
}