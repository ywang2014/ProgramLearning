package Day3;

import Day2.IO.StdDraw;

public class Triangle
{
	public static void main(String[] args)
	{
		double t = Math.sqrt(3.0) / 2.0;
		StdDraw.line(0.0, 0.1, 1.0, 0.1);
		StdDraw.line(1.0, 0.1, 0.5, t);
		StdDraw.line(0.5, t, 0.0, 0.1);
		StdDraw.point(0.5, t/3.0);
		
	}
}
