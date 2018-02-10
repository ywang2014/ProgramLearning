/**
	通过前缀码字典查找树构建编译表
*/
private static String[] buildCode(Node root){
	String[] st = new String[R];
	buildCode(st, root, "");
	return st;
}

private static void buildCode(String[] st, Node x, String s){
	if (x.isLeaf()){
		st[x.ch] = s;
		return ;
	}
	
	buildCode(st, x.left, s+'0');
	buildCode(st, x.right, s+'1'); 
}