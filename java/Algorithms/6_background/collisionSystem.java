/**
	基于事件模拟互相碰撞的粒子
*/
public class CollisionSystem{
	private class Event implements Comparable<Event>{
		// TODO
	}
	
	private MinPQ<Event> pq;
	private double t = 0.0;
	private Particle[] particles;
	
	public CollisionSystem(Particle[] particles){
		this.particles = particles;
	}
	
	private void predictCollisions(Particle a, double limit){
		//TODO 
	}
	
	public void redraw(double limit, double Hz){
		StdDraw.clear();
		for (int i = 0; i < particles.length; i++){
			particles[i].draw();
		}
		StdDraw.show(20);
		if (t < limit){
			pq.insert(new Event(t+1.0/Hz, null, null));
		}
	}
	
	public void simulate(double limit, double Hz){
		//TODO 
	}
	
	public static void main(String[] args){
		StdDraw.show(0);
		int N = Integer.parseInt(args[0]);
		Particle[] particles = new Particle[N];
		
		for (int i = 0; i < N; i++){
			particles[i] = new Particle();
		}
		CollisionSystem system = new CollisionSystem(particles);
		system.simulate(10000, 0.5);
	}
}