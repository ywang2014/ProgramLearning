/**
	Rabin-Karp指纹字符串查找算法
*/
public class RabinKarp{
	private String pat;
	private long patHash;
	private int M;
	private long Q;
	private int R = 256;
	private long RM;
	
	public RabinKarp(String pat){
		this.pat = pat;
		this.M = pat.length();
		Q = longRandomPrime();
		RM = 1;
		for (int i = 1; i <= M-1; i++){
			RM = (R * RM) % Q;
		}
		patHash = hash(pat, M);
	}
	
	public boolean check(int i){
		// TODO
		
		
		return true;
	}
	
	private long hash(String key, int M){
		long h = 0;
		for (int i = 0; i < M; i++){
			h = (h * R + key.charAt(i)) % Q;
		}
		return h;
	}
	
	private int search(String txt){
		int N = txt.length();
		long txtHash = hash(txt, M);
		if (patHash == txtHash && check(0)){
			return 0;
		}
		for (int i = M; i < N; i++){
			txtHash = (txtHash + Q - RM * txt.charAt(i - M) % Q) % Q;
			txtHash = (txtHash * R + txt.charAt(i)) % Q;
			if (patHash == txtHash){
				if (check(i-M+1)){
					return i-M+1;
				}
			}
		}
		return N;
	}
}