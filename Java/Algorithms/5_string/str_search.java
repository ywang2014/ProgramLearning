/**
	暴力子字符串查找
*/
public static int search(String pat, String txt){
	int M = pat.length();
	int N = txt.length();
	
	for (int i = 0; i <= N-M; i++){
		int j = 0;
		for (; j < M; j++){
			if (txt.charAt(i+j) != pat.charAt(j)){
				break;
			}
		}
		if (j == M){
			return i;
		}
	}
	return N;
}

// 显式回退的方法
public static int search(String pat, String txt){
	int M = pat.length();
	int N = txt.length();
	
	int i = 0;
	int j = 0;
	
	for (; i < N && j < M; i++){
		if (txt.charAt(i) == pat.charAt(j)){
			j++;
		}
		else{
			i -= j;
			j = 0;
		}
	}
	
	if (j == M){
		return i - M;
	}
	else{
		return N;
	}
}