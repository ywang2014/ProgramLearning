/**
	检查流量网络中的一种配置是否可行
*/
private boolean localEq(FlowNetwork g, int v){
	double EPSILON = 1E-11;
	double netflow = 0.0;
	for (FlowEdge e : g.adj(v)){
		if (v == e.from()){
			netflow -= e.flow();
		}
		else{
			netflow += e.flow();
		}
	}
	return Math.abs(netflow) < EPSILON;
}

private boolean isFeasible(FlowNetwork g){
	for (int v = 0; v < g.V(); v++){
		for (FlowEdge e : g.adj(v)){
			if (e.flow() < 0 || e.flow() > e.cap()){
				return false;
			}
		}
	}
	
	for (int v = 0; v < g.V(); v++){
		if (v != s && v != t && !localEq(v)){
			return false;
		}
	}
	
	return true;
}