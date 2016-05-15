/**
	BFS
*/
void search(Node root){
	Queue que = new Queue();
	root.visited = true;
	visit(root);
	que.enqueue(root);
	
	while (!que.isEmpty()){
		Node r = que.dequeue();
		foreach (Node n in r.adjacent){	// 图中adjacent实际就相当于孩子节点
			if (n.visited == false){
				visit(n);
				n.visited = true;
				que.enqueue(n);
			}
		}
	}
}