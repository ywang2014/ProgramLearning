/**
	游程编码
*/
public class RunLengthEncoding{
	public static void compress(){
		char cnt = 0;
		boolean b;
		boolean old = false;
		
		while (!BinaryStdIn.isEmpty()){
			b = BinaryStdIn.readBoolean();
			if (b != old){
				BinaryStdOut.write(cnt);
				cnt = 0;
				old = b;
			}
			else{
				if (cnt == 255){
					BinaryStdOut.write(cnt);
					cnt = 0;
					BinaryStdOut.write(cnt);
				}
			}
			cnt++;
		}
		BinaryStdOut.write(cnt);
		BinaryStdOut.close(); 
	}
	
	public static void expand(){
		boolean b = false;
		while (!BinaryStdIn.isEmpty()){
			char cnt = BinaryStdIn.readChar();
			for (int i = 0; i < cnt; i++){
				BinaryStdOut.write(b);
			}
			b = !b;
		}
		BinaryStdOut.close();
	}
}