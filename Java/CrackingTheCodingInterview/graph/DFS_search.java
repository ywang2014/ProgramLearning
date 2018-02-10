/**
	DFS
*/
void search(Node root){
	if (root == null){
		return;
	}
	visit(root);
	root.visited = true;
	foreach(Node n in root.adjacent){	// 图中adjacent实际就相当于孩子节点
		if (n.visited == false){
			search(n);
		}
	}
}