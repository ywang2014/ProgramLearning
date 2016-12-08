/**
	基因数据的展开方法
*/
public static void expand(){
	Alphabet DNA = new Alphabet("ACTG");
	int w = DNA.lgR();
	int N = BinaryStdIn.readInt();
	for (int i = 0; i < N; i++){
		char c = BinaryStdIn.readChar(w);
		BinaryStdOut.write(DNA.toChar(c));
	}
	BinaryStdOut.close();
}