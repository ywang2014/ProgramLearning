#include <string.h>
#include <limits.h>
#include "assert.h"
#include "fmt.h"
#include "str.h"
#include "mem.h"

// macros
// 位置与下标索引的映射
#define idx(i, len) ( ((i) <= 0) ? ((i) + (len)) : ((i) - 1) )

#define convert(s, i, j) do{\
	int len;	\
	assert(s);	\
	len = strlen(s);	\
	i = idx(i, len);	\
	j = idx(j, len);	\
	if (i > j){	\
		int t = i; 	\
		i = j;	\
		j = t;	\
	}	\
	assert(i >= 0 && j <= len);	\
} while (0)


// functions
char *Str_sub(const char *s, int i, int j){
	char *str;
	char *p;
	
	convert(s, i, j);
	
	p = str = ALLOC(j - i + 1);
	while (i < j){
		*p++ = s[i++];
	}
	*p = '\0';
	
	return str;
}


char *Str_dup(const char *s, int i, int j, int n){
	int index;
	char *str;
	char *p;
	
	assert(n >= 0);
	
	convert(s, i, j);
	p = str = ALLOC(n * (j - 1) + 1);
	if (j - i > 0){
		while (n-- > 0){
			for (index = i; index < j; index++){
				*p++ = s[index];
			}
		}
	}
	*p = '\0';
	
	return str;
}


char *Str_reverse(const char *s, int i, int j){
	char *str;
	char *p;
	
	convert(s, i, j);
	
	p = str = ALLOC(j - i + 1);
	while (i < j){
		*p++ = s[--j];
	}
	*p = '\0';
	
	return str;
}


char *Str_cat(const char *s1, int i1, int j1, const char *s2, int i2, int j2){
	char *str;
	char *p;
	
	convert(s1, i1, j1);
	convert(s2, i2, j2);
	
	p = str = ALLOC(j1 - i1 + j2 - i2 + 1);
	while (i1 < j1){
		*p++ = s1[i1++];
	}
	while (i2 < j2){
		*p++ = s2[i2++];
	}
	*p = '\0';
	
	return str;
}


char *Str_catv(const char *s, ...){
	char *str;
	char *p;
	const char *save = s;
	int i;
	int j;
	int len = 0;
	va_list ap;
	
	va_start(ap, s);
	// len <- the length of the result
	while (s){
		i = va_arg(ap, int);
		j = va_arg(ap, int);
		convert(s, i, j);
		len += j - i;
		s = va_arg(ap, const char *);
	}	
	va_end(ap);
	
	p = str = ALLOC(len + 1);
	
	s = save;
	va_start(ap, s);
	// copy each s[i:j] to p, increment p 
	while (s){
		i = va_arg(ap, int);
		j = va_arg(ap, int);
		convert(s, i, j);
		while (i < j){
			*p++ = s[i++];
		}
		s = va_arg(ap, const char *);
	}
	va_end(ap);
	
	*p = '\0';
	
	return str;
}


char *Str_map(const char *s, int i, int j, const char *from, const char *to){
	static char map[256] = {0};
	
	if (from && to){
		// rebuild map 
		unsigned c;
		for (c = 0; c < sizeof(map); c++){
			map[c] = c;
		}
		while (*from && *to){
			map[(unsigned char)*from++] = *to++;
		}
		assert(*from == 0 && *to == 0);
	}
	else{
		assert(from == NULL && to == NULL && s);
		assert(map['a']);	// ? map[]={ 0 }
	}
	
	if (s){
		// map s[i:j] into a new string
		char *str;
		char *p;
		
		convert(s, i, j);
		
		p = str = ALLOC(j - i + 1);
		while (i < j){
			*p++ = map[ (unsigned char)s[i++] ];
		}
		*p = '\0';
		
		return str;
	}
	else{
		return NULL;
	}
}


int Str_pos(const char *s, int i){
	int len;
	
	assert(s);
	
	len = strlen(s);
	i = idx(i, len);
	assert(i >= 0 && i <= len);
	
	return i + 1;
}


int Str_len(const char *s, int i, int j){
	assert(s);
	
	convert(s, i, j);
	
	return j - i;
}


int Str_cmp(const char *s1, int i1, int j1, const char *s2, int i2, int j2){
	// if (s1 == NULL)
	// {
		// if (s2 == NULL){
			// return 0;
		// }
		// else{
			// return -1;
		// }
	// }
	// else
	// {
		// if (s2 == NULL){
			// return 1;
		// }
		// else{
			// char *p1 = Str_sub(s1, i1, j1);
			// char *p2 = Str_sub(s2, i2, j2);
			
			// return strcmp(p1, p2);
		// }
	// }
	
	// string compare
	convert(s1, i1, j1);
	convert(s2, i2, j2);
	
	s1 += i1;
	s2 += i2;
	
	if ((j1 - i1) < (j2 - i2)){
		int cond = strncmp(s1, s2, j1 - i1);
		return cond == 0 ? -1 : cond;	// 因为截断了一部分，所以需要转换0的意义
	}
	else if ((j1 - i1) > (j2 - i2)){
		int cond = strncmp(s1, s2, j2 - i2);
		return cond == 0 ? 1 : cond;
	}
	else{
		return strncmp(s1, s2, j1 - i1);
	}
}


int Str_chr(const char *s, int i, int j, int c){
	assert(s);
	
	convert(s, i, j);
	
	for (; i < j; i++){
		if (s[i] == c){
			return i + 1;
		}
	}
	
	return 0;
}


int Str_rchr(const char *s, int i, int j, int c){
	assert(s);
	
	convert(s, i, j);
	
	while (i < j){
		if (s[--j] == c){
			return j + 1;
		}
	}
	
	return 0;
}


int Str_upto(const char *s, int i, int j, const char *set){
	assert(s && set);
	
	convert(s, i, j);
	
	while (i < j){
		if (strchr(set, s[i++])){
			return i;
		}
	}
	return 0;
}


int Str_rupto(const char *s, int i, int j, const char *set){
	assert(s && set);
	
	convert(s, i, j);
	
	while (i < j){
		if (strchr(set, s[--j])){
			return j + 1;
		}
	}
	return 0;
}


int Str_find(const char *s, int i, int j, const char *str){
	int len;
	
	assert(s && str);
	
	convert(s, i, j);
	
	len = strlen(str);
	if (len == 0){
		return i + 1;
	}
	else if (len == 1){
		while (i < j){
			if (s[i++] == *str){
				return i;
			}
		}
	}
	else{
		while (i + len <= j){
			// s[i...] = str[0...len-1]
			if (strncmp(&s[i], str, len) == 0){
				return i + 1;
			}
			i++;
		}
	}
	
	return 0;
}


int Str_rfind(const char *s, int i, int j, const char *str){
	int len;
	
	assert(s && str);
	
	convert(s, i, j);
	
	len = strlen(str);
	if (len == 0){
		return j+1;
	}
	else if (len == 1){
		while (i < j){
			if (s[--j] == *str){
				return j + 1;
			}
		}
	}
	else{
		while (i <= j - len){
			if (strncmp(&s[j-len], str, len) == 0){
				return j - len + 1;
			}
			j--;
		}
	}
	
	return 0;
}


// s[i] 是否在集合中
int Str_any(const char *s, int i, const char *set){
	int len;
	
	assert(s && set);
	
	len = strlen(s);
	i = idx(i, len);
	assert(0 <= i && i <= len);
	if (i < len && strchr(set, s[i])){
		return i + 2;	// ?
	}
	
	return 0;
}


// s[i]是否在集合中，返回其连续子串都在集合中，最后一个字符位置
int Str_many(const char *s, int i, int j, const char *set){
	assert(s && set);
	
	convert(s, i, j);
	
	if (i < j && strchr(set, s[i])){
		do{
			i++;
		} while (i < j && strchr(set, s[i]));
		
		return i + 1;
	}
	
	return 0;
}


int Str_rmany(const char *s, int i, int j, const char *set){
	assert(s && set);
	
	convert(s, i, j);
	
	if (i < j && strchr(set, s[--j]){
		do{
			j--;
		} while (j >= i && strchr(set, s[j]);
		
		return j + 2;
	}
	
	return 0;
}


int Str_match(const char *s, int i, int j, const char *str){
	int len;
	
	assert(s && str);
	
	convert(s, i, j);
	
	len = strlen(str);
	if (len == 0){
		return i + 1;
	}
	else if (len == 1){
		if (i < j && s[i] == *str){
			return i + 2;
		}
	}
	// s[i...] = str[0...len-1]
	else if (i + len <= j && strncmp(&s[i], str, len) == 0){
		return i + len + 1;
	}
	
	return 0;
}


int Str_rmatch(const char *s, int i, int j, const char *str){
	int len;
	
	assert(s && str);
	
	convert(s, i, j);
	
	len = strlen(str);
	if (len == 0){
		return j + 1;
	}
	else if (len == 1){
		if (i < j && s[--j] == *str){
			return j + 1;
		}
	}
	else if (i + len <= j && strncmp(&s[j-len], str, len) == 0){
		return j - len + 1;
	}
	
	return 0;
}


void Str_fmt(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	char *s;
	int i;
	int j;
		
	assert(app && flags);
	
	s = va_arg(*app, char *);	// 可变参数列表，va_list *app,当做参数传递进来的
	i = va_arg(*app, int);
	j = va_arg(*app, int);
	convert(s, i, j);
	
	Fmt_put(s+i, j-i, put, c1, flags, width, precision);
}