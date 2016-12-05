/**
	Knuth-Morris-Pratt 字符串查找算法
*/
public class KMP{
	private String pat;
	private int[][] dfa;
	
	public KMP(String pat){
		this.pat = pat;
		int M = pat.length();
		int R = 256;
		dfa = new int[R][M];
		dfa[pat.charAt(0)][0] = 1;
		for (int x = 0, j = 1; j < M; j++){
			for (int c = 0; c < R; c++){
				dfa[c][j] = dfa[c][x];		// 复制匹配失败情况下的值
			}
			dfa[pat.charAt(j)][j] = j + 1;	// 设置匹配成功情况下的值
			x = dfa[pat.charAt(j)][x];		// 更新重启状态
		}
	}
	
	public int search(String txt){
		int i = 0;
		int j = 0;
		int N = txt.length();
		int M = pat.length();
		
		while (i < N && j < M){
			j = dfa[txt.charAt(i)][j];
			i++;
		}
		
		if (j == M){
			return i - M;
		}
		else{
			return N;
		}
	}
	
	public static void main(String[] args){
		//
	}
}