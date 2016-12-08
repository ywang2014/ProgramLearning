/**
	基因数据的压缩方法
*/
public static void compress(){
	Alphabet DNA = new Alphabet("ACTG");
	String s = BinaryStdIn.readString();
	int N = s.length();
	BinaryStdOut.write(N);
	for(int i = 0; i < N; i++){
		int d = DNA.toIndex(s.charAt(i));
		BinaryStdOut.write(d, DNA.lgR());
	}
	BinaryStdOut.close();
}
