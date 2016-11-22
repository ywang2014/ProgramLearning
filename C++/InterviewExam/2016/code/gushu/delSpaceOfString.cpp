/**
	删除给定的字符串中的空格：
	比如："ABD aaa  edf" ---> "ABDaaaedf"
*/
char delSpaceOfString(char *str){
	if (str == NULL){
		return NULL;
	}
	
	char *current = str;
	char *p = str;
	while (*current != '\0'){
		if (*current == ' '){
			current++;
		}
		else{
			*p++ = *current++;
		}
	}
	*p = '\0';
	
	return str;
}