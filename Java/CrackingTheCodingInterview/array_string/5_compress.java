/**
	利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能.
	若压缩后的字符串没有变短，则返回原先字符串。
	aabcccccc -> a2b1c5a3
*/
// 版本一
public String compressBad(String str){
	String mystr = "";
	char last = str.charAt(0);
	int count = 1;
	for (int i = 1; i < str.length(); i++){
		if (str.charAt(i) == last){
			count++;
		}
		else{
			mystr += last + "" + count;
			count = 1;
			last = str.charAt(i);
		}
	}
	mystr += last + count;
	
	return mystr.length() >= str.length() ? str : mystr;
}

String compressBetter(String str){
	int size = countCompression(str);
	if (size >= str.length()){
		return str;
	}
	
	StringBuffer mystr = new StringBuffer();
	char last = str.charAt(0);
	int count = 1;
	for (int i = 1; i < str.length(); i++){
		if (str.charAt(i) == last){
			count++;
		}
		else{
			mystr.append(last);
			mystr.append(count);
			last = str.charAt(i);
			count = 1;
		}
	}
	mystr.append(last);
	mystr.sppend(count);
	
	return mystr.toString();
}


int countCompression(String str){
	if (str == null || str.isEmpty()){
		return 0;
	}
	
	char last = str.charAt(0);
	int count = 1;
	int length = 0;
	
	for (int i = 1; i < str.length(); i++){
		if (str.charAt(i) == last){
			count++;
		}
		else{
			length += 1 + String.valueOf(count).length();
			last = str.charAt(i);
			count = 1;
		}
	}
	size += 1 + String.valueOf(count).length();
	
	return size;
}