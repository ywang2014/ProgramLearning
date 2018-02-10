package Day3;

import Day2.IO.StdDraw;

public class BallMove
{
	public static void main(String[] args)
	{
		final int WIDTH = 400;
		final int HEIGHT = 400;
		double y = 0;
		
		StdDraw.setCanvasSize(WIDTH, HEIGHT);
		StdDraw.setXscale(0, WIDTH);
		StdDraw.setYscale(0, HEIGHT);
		
		for (int i = 0; i < 360; i++)
		{
			y = Math.sin(1.0 * i / 360 * Math.PI * 2);
			//StdDraw.text(i, HEIGHT-100, String.valueOf(y));
			StdDraw.circle(i, HEIGHT/2 * (1 + y), 10);
			StdDraw.show(50);
		}
		
		for (int i = 0; i < 100; i++)
		{
			StdDraw.clear();
			int x1 = (int)(Math.random()*WIDTH);
			int y1 = (int)(Math.random()*HEIGHT);
			StdDraw.setPenColor(StdDraw.CYAN);
			StdDraw.filledCircle(x1, y1, 10);
			StdDraw.show(200);
		}
		
		double ball_x = 48, ball_y = 60;
		double vel_x = 1, vel_y = 2.3;	// 因为速度较小，一次改变很少，所以看起来是连续运动，实际也是跳跃的
		int radius = 10;
		while (true)
		{
			// bounce off wall according to law of elastic collision
			if ((ball_x + vel_x) > (WIDTH - radius) || (ball_x + vel_x) < radius)
			{
				vel_x = -vel_x;
			}
			if ((ball_y + vel_y) > (HEIGHT - radius) || (ball_y + vel_y) < radius)
			{
				vel_y = -vel_y;
			}
			
			// update position
			ball_x += vel_x;
			ball_y += vel_y;
			
			// clear the background
			StdDraw.clear(StdDraw.GRAY);
			
			// draw ball on the screen
			StdDraw.setPenColor(StdDraw.BLACK);
			StdDraw.filledCircle(ball_x, ball_y, radius);
			
			// display and pause for 20ms
			StdDraw.show(20);
		}
	}
}
