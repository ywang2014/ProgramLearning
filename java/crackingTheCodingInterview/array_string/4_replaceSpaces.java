/**
	将字符串里面的空格替换为%20
*/
public void replaceSpaces(char[] str, int length){
	int spaces = 0;
	for (int i = 0; i < length; i++){
		if (str[i] == ' '){
			spaces++;
		}
	}
	
	int newlength = length + 2 * spaces;
	str[newlength] = '\0';
	for (int i = length - 1; i >= 0; i--){
		if (str[i] == ' '){
			str[--newlength] = '0';
			str[--newlength] = '2';
			str[--newlength] = '%';
		}
		else{
			str[--newlength] = str[i];
		}
	}
}