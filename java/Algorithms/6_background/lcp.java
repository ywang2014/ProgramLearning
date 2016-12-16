/**
	两个字符串的最长公共前缀
*/
private static int lcp(String a, String b){
	int N = Math.min(a.length(), b.length());
	for (int i = 0; i < N; i++){
		if (a.charAt(i) != b.charAt(i)){
			return i;
		}
	}
	return N;
}