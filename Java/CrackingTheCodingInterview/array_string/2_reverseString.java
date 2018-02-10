/**
	反转字符串
*/
public static String reverseString(String str){
	int n = str.length();
	char[] s = new char[n];
	
	for (int i = 0; i < n; i++){
		s[i] = str.charAt(n-1-i);
	}
	
	return new String(s);
}

// C++
void reverse(char *str){
	char *start = str;
	char *end = str;
	while (*end != '\0'){
		end++;
	}
	end--;
	
	while (start != end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}