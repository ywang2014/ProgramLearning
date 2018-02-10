/**
	KMP字符串查找算法中的DFA的构造
*/
dfa[pat.charAt(0)][0] = 1;
for (int x = 0, j = 1; j < M; j++){
	for (int c = 0; c < R; c++){
		dfa[c][j] = dfa[c][x];
	}
	dfa[pat.charAt(j)][j] = j + 1;
	x = dfa[pat.charAt(j)][x];
}