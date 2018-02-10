package chapter2.day1;

import javax.swing.JFrame;

import java.awt.Color;
import java.awt.Graphics;

public class Function
{
	// absolute value of an integer 
	public static int abs(int value)
	{
		return value < 0 ? -value : value;
	}
	
	// absolute value of double
	public static double abs(double value)
	{
		return value < 0 ? -value : value;
	}
	
	// primality test
	public static boolean isPrime(int N)
	{
		if (N < 2)
		{
			return false;
		}
		
		for (int i = 2; i < N/i; i++)
		{
			if (N % i == 0)
			{
				return false;
			}
		}
		
		return true;
	}
	
	// hypotenuse of a right triangle
	public static double hypotenuse(double side_a, double side_b)
	{
		return Math.sqrt(side_a * side_a + side_b * side_b);
	}
	
	// Harmonic number
	public static double harmonic(int N)
	{
		double sum = 0.0;
		for (int i = 1; i < N; i++)
		{
			sum += 1 / i;
		}
		return sum;
	}
	
	// uniform random integer in [0, n)
	public static int uniform(int N)
	{
		return (int)Math.random() * N;
	}
	
	// draw a triangle to standard draw (side effects)
	public static void drawTriangle(double x0, double y0, double x1, double y1, double x2, double y2)
	{
		DrawTri dt = new DrawTri(x0, y0, x1, y1, x2, y2);
	}
	
	public static void main(String[] args)
	{
		drawTriangle(100, 100, 200, 200, 300, 100);
	}
}

class DrawTri extends JFrame
{
	private int x0;
	private int y0;
	private int x1;
	private int y1;
	private int x2;
	private int y2;
	
	public DrawTri(double x0, double y0, double x1, double y1, double x2, double y2)
	{
		setTitle("Triangle");
		setSize(400, 300);
		setResizable(false);	// 设置窗口是否可以调整大小
		setVisible(true);	// 窗口可见
		
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		this.x0 = (int)x0;
		this.y0 = (int)y0;
		this.x1 = (int)x1;
		this.y1 = (int)y1;
		this.x2 = (int)x2;
		this.y2 = (int)y2;
	}
	
	public void setCoordinate(double x0, double y0, double x1, double y1, double x2, double y2)
	{
		this.x0 = (int)x0;
		this.y0 = (int)y0;
		this.x1 = (int)x1;
		this.y1 = (int)y1;
		this.x2 = (int)x2;
		this.y2 = (int)y2;
	}
	
	public void paint(Graphics g)
	{
		g.setColor(Color.BLUE);
		g.drawLine(x0, y0, x1, y1);
		g.drawLine(x1, y1, x2, y2);
		g.drawLine(x2,  y2,  x0, y0);
	}
}