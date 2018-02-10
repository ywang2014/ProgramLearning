/**
	LZW压缩算法
*/
public class LZW{
	private static final int R = 256;	// 输入字符数
	private static final int L = 4096;	// 编码总数=2^12 
	private static final int W = 12;	// 编码宽度
	
	public static void compress(){
		String input = BinaryStdIn.readString();
		TST<Integer> st = new TST<Integer>();
		
		for (int i = 0; i < R; i++){
			st.put("" + (char) i, i);
		}
		int code = R + 1;	// EOF文件结束符
		
		while (input.length() > 0){
			String s = st.longestPrefixOf(input);
			BinaryStdOut.write(st.get(s), w);
			
			int t = s.length();
			if (t < input.length() && code < L){
				st.put(input.subString(0, t+1), code++);
			}
			input = input.subString(t);
		}
		BinaryStdOut.write(R, W);
		BinaryStdOut.close();
	}
	public static void expand(){
		// TODO
		String[] st = new String[L];
		int i;
		for (i = 0; i < R; i++){
			st[i] = "" + (char) i;
		}
		st[i++] = " ";	// EOF
		
		int codeword = BinaryStdIn.readInt(w);
		String val = st[codeword];
		
		while (true){
			BinaryStdOut.write(val);
			codeword = BinaryStdIn.readInt(W);
			if (codeword == R){
				break;
			}
			String s = st[codeword];
			if (i == codeword){
				s = val + val.charAt(0);
			}
			if (i < L){
				st[i++] = val + s.charAt(0);
			}
			val = s;
		}
		
		BinaryStdOut.close();
	}
}