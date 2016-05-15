/**
	判断有向图图中的两点之间是否有一条路径
*/	
public enum State{
	Unvisited, Visited, Visiting;
}

public static boolean search(Graph g, Node start, Node end){
	LinkedList<Node> q = new LinkedList<Node>();	// stack
	for (Node u : g.getNodes()){
		u.state = State.Unvisited;
	}
	start.state = State.Visiting;
	q.add(start);				// push()
	Node u;
	while (!q.isEmpty()){
		u = q.removeFirst();	// pop()
		if (u != null){
			for (Node V : u.getAdjacent()){
				if (v.state == State.Unvisited){
					if (v == end){
						return true;
					}
					else{
						v.state = State.Visiting;
						q.add(v);
					}
				}
			}
			u.state = State.Visited;
		}
	}
	return false;
}