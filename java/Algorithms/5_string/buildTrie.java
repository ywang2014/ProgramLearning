/**
	霍夫曼编码的单词查找树
*/
private static Node buildTrie(int[] freq){
	MinPQ<Node> pq = new MinPQ<Node>();
	for (char ch = 0; ch < R; ch++){
		if (freq[c] > 0){
			pq.insert(new Node(c, freq[c], null, null));
		}
	}
	
	while (pq.size() > 1){
		Node x = pq.delMin();
		Node y = pq.delMin();
		Node parent = new Node('\0', x.freq+y.freq, x, y);
		pq.insert(parent);
	}
	return pq.delMin();
}