/**
	前缀编码的解码
*/
public static void expand(){
	Node root = readTrie();
	int N = BinaryStdIn.readInt();
	for (int i = 0; i < N; i++){
		Node x = root;
		while (!x.isLeaf()){
			if (BinaryStdIn.readBoolean()){
				x = x.right();
			}
			else{
				x = x.left;
			}
		}
		BinaryStdOut.write(x.ch);
	}
}

public static void compress(){
	//...
	
	for (int i = 0; i < input.length; i++){
		String code = st[input[i]];
		for (int j = 0; j < code.length(); j++){
			if (code.charAt(j) == '1'){
				BinaryStdOut.write(true);
			}
			else{
				BinaryStdOut.write(false);
			}
		}
	}
}