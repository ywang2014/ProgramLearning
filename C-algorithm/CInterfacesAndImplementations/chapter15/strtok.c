/**
	strtok()的实现
	
	char *strtok(char *s, const char *set);
	
	将s分成由集合s中的字符分离的记号。通过反复调用strtok，将字符串s分成多个记号。
	
	s只有在第一次调用strtok是才被传递，并且strtok搜索第一个在set中出现的字符，用一个空字符覆盖，并返回s
	随后调用strtok，将使strtok在它离开的位置，继续搜索第一个在set中的字符，空字符替换，然后返回指向所代表字符串的头部指针。
	strtok(NULL, set);
	
	搜索失败，返回空值。
*/

// 标记上次strtok结束的地方，的下一个位置，作为下次调用的返回值
static char *newHead = NULL;

char *strtok(char *s, const char *set){
	
	assert(set);
	
	if (s != NULL){
		int len = strlen(s);
		char *p = s;
		
		while (*p != '\0'){
			if (strchr(set, *p) != NULL){
				newHead = ((p + 1) < (s + len)) ? (p + 1) : NULL;
				*p = '\0';
			}
			p++;
		}
		
		return (*p == '\0') ? NULL : s;
	}
	else{
		char *oldHead;
		char *p;
		char len;
		
		assert(newHead);
		
		p = oldHead = newHead;
		len = strlen(newHead);
		while (*p != '\0'){
			if (strchr(set, *p) != NULL){
				newHead = ((p + 1) < (newHead + len)) ? (p + 1) : NULL;
				*p = '\0';
			}
			p++;
		}
		
		return (*p == '\0') ? NULL : oldHead;
	}
}


// 版本二， 优化版
char *strtok(char *s, const char *set){
	int len;
	char *p;
	char oldHead;
	
	assert(set);
	
	p = oldHead = (s != NULL) ? s : newHead;
	
	assert(oldHead);
	
	len = strlen(oldHead);
	while (*p != '\0'){
		if (strchr(set, *p) != NULL)
		{
			newHead = ((p + 1) < (oldHead + len)) ? (p + 1) : NULL;
			*p = '\0';
		}
		p++;
	}
	
	return (*p == '\0') ? NULL : oldHead;
}


