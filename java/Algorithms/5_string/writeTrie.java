/**
	将单词查找树写入比特字符串
*/
private static void writeTrie(Node x){
	if (x.isLeaf()){
		BinaryStdOut.write(true);
		BinaryStdOut.write(x.ch);
		return ;
	}
	
	BinaryStdOut.write(false);
	writeTrie(x.left);
	writeTrie(x.right);
}