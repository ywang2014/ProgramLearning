/**
	检验一个字符串是否有重复字符
*/
public boolean isUniqueChars(String str){
	if (str.length() > 256)
	{
		return false;	// ASCII码，小于256
	}
	boolean[] charSet = new boolean[256];
	
	for (int i = 0; i < str.length(); i++){
		int val = str.charAt(i);
		if (charSet[val]){
			return false;
		}
		charSet[val] = true;
	}
	
	return true;
}