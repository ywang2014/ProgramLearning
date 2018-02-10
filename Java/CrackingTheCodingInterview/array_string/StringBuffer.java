/**
	字符串拼接
	
	使用String，需要O(n^2)时间复杂度
	使用StringBuffer，需要O(n)时间复杂度
*/

public String joinWords(String[] words){
	String sentence = "";
	for (String w : words){
		sentence = sentence + w;	// String每次拼接都会创建一个字符串，存储结果
	}
	
	return sentence;
}

public String joinWords(String[] words){
	StringBuffer sentence = new StringBuffer();
	for (String w : words){
		sentence.append(w);
	}
	
	return sentence.toString();
}