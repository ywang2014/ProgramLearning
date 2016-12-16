/**
	预测其他粒子的碰撞事件
*/
private void predictCollisions(Particle a, double limit){
	if (a == null){
		return ;
	}
	for (int i = 0; i < particles.length; i++){
		double dt = a.timeToHit(particles[i]);
		if (t + dt <= limit){
			pq.insert(new Event(t+dt, a, particles[i]));
		}
	}
	double dtX = a.timeToHitVerticalWall();
	if (t + dtX <= limit){
		pq.insert(new Event(t+dtX, a, null));
	}
	double dtY = a.timeToHitHorizontalWall();
	if (t + dtY <= limit){
		pq.insert(new Event(t+dtY, null, a));
	}
}