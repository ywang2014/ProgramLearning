/**
 * 读取USA.txt文件中的点坐标，可以绘制美国地图
 */
package Day3;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Scanner;

import Day2.IO.StdDraw;

public class PlotFilter
{
	public static void main(String[] args)
	{
		InputStream in = null;
		try
		{
			in = new FileInputStream(new File("./src/Day3/USA.txt"));
		}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
		
		Scanner s = new Scanner(in);
		
		double[] rectangle  = {s.nextDouble(), s.nextDouble(), s.nextDouble(), s.nextDouble()};
		StdDraw.setXscale(rectangle[0], rectangle[2]);
		StdDraw.setYscale(rectangle[1], rectangle[3]);
		StdDraw.line(rectangle[0], rectangle[1], rectangle[2], rectangle[1]);
		StdDraw.line(rectangle[2], rectangle[1], rectangle[2], rectangle[3]);
		StdDraw.line(rectangle[2], rectangle[3], rectangle[0], rectangle[3]);
		StdDraw.line(rectangle[0], rectangle[3], rectangle[0], rectangle[1]);
		
		double x = 0.0;
		double y = 0.0;
		while (! s.hasNext())
		{
			x = s.nextDouble();
			y = s.nextDouble();
			StdDraw.point(x, y);
		}
		
		//StdDraw.show(0);
		s.close();
	}
	
}
