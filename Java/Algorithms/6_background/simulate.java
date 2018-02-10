/**
	 基于事件模拟相互碰撞的粒子 -- simulate
*/
public void simulate(double limit, double Hz){
	pq = new MinPA<Event>();
	for (int i = 0; i < particles.length; i++){
		predictCollisions(particles[i], limit);
	}
	pq.insert(new Event(0, null, null));
	while (!pq.isEmpty()){
		Event event = pq.delMin();
		if (!event.isValid()){
			continue;
		}
		for (int i = 0; i < particles.length; i++){
			particles[i].move(event.time - t);
		}
		t = event.time;
		Particle a = event.a, b = event.b;
		if (a != null && b != null){
			a.bounceOff(b);
		}
		else if (a != null && b == null){
			a.bounceOffHorizontalWall();
		}
		else if (a == null && b != null){
			b.bounceOffVerticalWall();
		}
		else if (a == null && b == null){
			redraw(limit, Hz);
		}
		predictCollisions(a, limit);
		predictCollisions(b, limit);
	}
}