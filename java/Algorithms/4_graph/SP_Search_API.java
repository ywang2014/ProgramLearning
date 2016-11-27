/**
	最短路径API
*/
public double distTo(int v){
	return distTo[v];
}

public boolean hasPathTo(int v){
	return distTo[v] < Double.POSITIVE_INFINITY;
}

public Iterable<DirectedEdge> pathTo(int v){
	if (!hasPathTo(v)){
		return null;
	}
	Stack<DirectedEdge> path = new Stack<DirectedEdge>();
	for (DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.from()]){
		path.push(e);
	}
	return path;
}