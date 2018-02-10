/**
	KMP字符串查找算法 -- DFA
*/
public int search(String txt){
	int i = 0;
	int j = 0;
	int N = txt.length();
	
	for (; i < N && j < M; i++){
		j = dfa[txt.charAt(i)][j];
	}
	if (j == M){
		return i - M;
	}
	else{
		return N;
	}
}