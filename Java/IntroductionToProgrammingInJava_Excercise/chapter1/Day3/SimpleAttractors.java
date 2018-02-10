/******************************************************************************
 *  Compilation:  javac SimpleAttractors.java
 *  Execution:    java SimpleAttractors N
 *  Dependencies: StdDraw.java
 *
 *  N particles are attracted to the mouse; randomly rearrange when
 *  user clicks.
 *
 *  % java SimpleAttractors 20
 *
 *  Credits:  Jeff Traer-Bernstein
 * 
 ******************************************************************************/

package Day3;

import Day2.IO.StdDraw;

public class SimpleAttractors {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double[] rx = new double[N];
        double[] ry = new double[N];
        double[] vx = new double[N];
        double[] vy = new double[N];
        double dt = 0.5;
        double mass = 1.0;
        double drag = 0.05;     // try changing this to 0.1 or 0.01 or even 0...
        double attractionStrength = 0.01;
        
        // initialize the drawing area
        StdDraw.setPenColor(StdDraw.BLUE);

        // do the animation
        while (true) {
            // if the mouse is pressed add some random velocity to all the particles
            if (StdDraw.mousePressed()) {
                for (int i = 0; i < N; i++) {
                    vx[i] = .2 * Math.random() - .1;
                    vy[i] = .2 * Math.random() - .1;
                }
            }
            
            // clear all the forces
            double[] fx = new double[N];
            double[] fy = new double[N];
            
            // add attraction forces for attraction to the mouse
            for (int i = 0; i < N; i++) {
                double dx = StdDraw.mouseX() - rx[i];
                double dy = StdDraw.mouseY() - ry[i];
                fx[i] += attractionStrength * dx;
                fy[i] += attractionStrength * dy;
            }
            
            // add drag forces to all particles
            // drag is proportional to velocity in the opposite direction
            for (int i = 0; i < N; i++) {
                fx[i] += -drag * vx[i];
                fy[i] += -drag * vy[i];
            }
            
            // update positions
            // euler step
            for (int i = 0; i < N; i++) {
                vx[i] += fx[i] * dt / mass;
                vy[i] += fy[i] * dt / mass;
                rx[i] += vx[i] * dt;
                ry[i] += vy[i] * dt;
            }
            
            
            StdDraw.clear();
            
            // draw a filled circle for each particle
            for (int i = 0; i < N; i++) {
                StdDraw.filledCircle(rx[i], ry[i], .01);
            }
            
            StdDraw.show(10);
        }
    }
}
