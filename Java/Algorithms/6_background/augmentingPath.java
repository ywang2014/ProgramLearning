/**
	在剩余网络中通过广度优先搜索寻找增广路径
*/
private boolean hasAugmentingPath(FlowNetwork g, int s, int t){
	marked = new boolean[g.V()];
	edgeTo = new FlowEdge[g.V()];
	Queue<Integer> q = new Queue<Integer>();
	
	marked[s] = true;
	q.enqueue(s);
	while (!q.isEmpty()){
		int v = q.dequeue();
		for (FlowEdge e : g.adj(v)){
			int w = e.other(v);
			if (e.residualCapacityTo(w) > 0 && !marked[w]){
				edgeTo[w] = e;
				marked[w] = true;
				q.enqueue(w);
			}
		}
	}
	return marked[t];
}