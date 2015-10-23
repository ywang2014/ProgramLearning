package Day3;

import Day2.IO.StdAudio;
import Day2.IO.StdDraw;

public class DeluxeBouncingBall
{
	public static void main(String[] args)
	{
		double x = 0.48, y = 0.68;	// position coordinate
		double vx = 0.015, vy = 0.03;	// ball velocity
		double radius = 0.03;	// a hack since "earth.gif" is in pixels
		
		// set the scale of the coordinate system
		StdDraw.setXscale(-1.0, 1.0);
		StdDraw.setYscale(-1.0, 1.0);
		
		// main animation loop
		while (true)
		{
			if (Math.abs(x + vx) + radius > 1.0)
			{
				vx = -vx;
				StdAudio.play("laser.wav");
			}
			if (Math.abs(y + vy) + radius > 1.0)
			{
				vy = -vy;
				StdAudio.play("pop.wav");
			}
			
			x += vx;
			y += vy;
			StdDraw.clear();
			StdDraw.picture(x, y, "earth.gif");
			StdDraw.show(20);
		}
	}
}
