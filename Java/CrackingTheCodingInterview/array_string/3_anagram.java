/**
	anagram 
*/
public String sort(String str){
	char[] content = s.toCharArray();
	java.util.Arrays.sort(content);
	return new String(content);
}

public boolean permutation(String s, String t){
	if (s.length() != t.length()){
		return false;
	}
	
	return sort(s).equals(sort(t));
}

// 高效算法
public boolean permutation(String s, String t){
	if (s.length() != t.length()){
		return false;
	}
	
	int[] letters = new int[256];
	
	char[] sArray = s.toCharArray();
	for (char c : sArray){
		letters[c]++;
	}
	
	for (int i = 0; i < t.length(); i++){
		int c = (int)t.charAt(i);
		letters[c]--;
		if (letters[c] < 0){
			return false;
		}
	}
	/*
		直接这样可行，不需要再遍历一次数组，因为字符串已经是等长的。
	*/
	return true;
}