/**
	KMP子字符串查找算法的测试用例
*/
public static void main(String[] args){
	String txt = args[0];
	String pat = args[1];
	KMP kmp = new KMP(pat);
	
	StdOut.println("text: " + txt);
	int offset = kmp.search(txt);
	StdOut.print("pattern: ");
	for (int i = 0; i < offset; i++){
		StdOut.print(" ");
	}
	StdOut.println(pat);
}