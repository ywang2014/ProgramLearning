/**
	读取单词查找树，从比特流中
*/
private static Node readTrie(Node x){
	if (!BinaryStdIn.isEmpty()){
		Boolean ch = BinaryStdIn.readBoolean();
		if (ch){
			char ch = BinaryStdIn.readChar();
			Node leaf = new Node(ch, 0, null, null);
			return leaf;
		}
		else{
			Node node = new Node('\0', 0, null, null);
			node.left = readTrie();
			node.right = readTrie();
			return node;
		}
	}
	return null;
}

////////////////////////////////////////////////
private static Node readTrie(){
	if (BinaryStdIn.readBoolean()){
		return new Node(BinaryStdIn.readChar(), 0, null, null);
	}
	return new Node('\0', 0, readTrie(), readTrie());
}