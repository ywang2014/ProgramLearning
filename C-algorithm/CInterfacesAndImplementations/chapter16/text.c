#incldue <string.h>
#include <limits.h>
#include "assert.h"
#include "fmt.h"
#inlcude "text.h"
#include "mem.h"

#define T Text_T

// macros
#define idx(i, len) ((i) <= 0 ? (i) + (len) : (i) - 1;

#define isatend(s, n) ((s).str + (s).len == current->avail \
	&& current->avail + (n) <= current->limit)
	
#define equal(s, i, str) \
	(memcmp(&(s).str[i], (t).str, (t).len) == 0)

// types
struct Text_save_T{
	struct chunk *current;
	char *avail;
};

// data
static char cset[] = {
	"\000\001\002\003\004\005\006\007\010\011\012\013\014\015\016\017"
	"\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037"
	"\040\041\042\043\044\045\046\047\050\051\052\053\054\055\056\057"
	"\060\061\062\063\064\065\066\067\070\071\072\073\074\075\076\077"
	"\100\101\102\103\104\105\106\107\110\111\112\113\114\115\116\117"
	"\120\121\122\123\124\125\126\127\130\131\132\133\134\135\136\137"
	"\140\141\142\143\144\145\146\147\150\151\152\153\154\155\156\157"
	"\160\161\162\163\164\165\166\167\170\171\172\173\174\175\176\177"
	"\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217"
	"\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237"
	"\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257"
	"\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277"
	"\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317"
	"\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337"
	"\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357"
	"\360\361\362\363\364\365\366\367\370\371\372\373\374\375\376\377"
};
const T Text_cset = { 256, cset };
const T Text_ascci = {127, cset };
const T Text_ucase = { 26, cset + 'A' };
const T Text_lcase = { 26, cset + 'a' };
const T Text_digits = { 10, cset + '0' };
const T Text_null = { 0, cset };

static struct chunk{
	struct chunk *link;
	char *avail;
	char *limit;
} head = { NULL, NULL, NULL }, *current = &head;

// static functions
static char *Text_alloc(int len){
	assert(len >= 0);
	
	if ((current->avail + len) > (cunrrent->limit)){
		current = current->link = ALLOC(sizeof(*current) + 10 * 1024 + len)
		current->avail = (char *)(current + 1);	// ? 为什么加1
		current->limit = current->avail + 10 * 1024 + len;
		current->link = NULL;
	}
	current->avail += len;
	
	return current->avail - len;
}


// functions 
int Text_pos(T s, int i){
	assert(s.len >= 0 && s.str);
	
	i = idx(i, s.len);
	assert(0 <= i && i <= s.len);
	
	return i + 1;
}


T Text_box(const char *str, int len){
	T text;
	
	assert(str);
	assert(len >= 0);
	
	text.str = str;
	text.len = len;
	
	return text;
}


T Text_sub(T s, int i, int j){
	T text;
	
	// convert i and j to indices in 0...s 
	// assert(s);
	// assert(s.str);
	// assert(s.len >= 0);
	
	// if (i < 0){
		// i += s.len;
	// }
	// if (j < 0){
		// j += s.len;
	// }
	// if (i > j){
		// int old_i = i;
		// i = j;
		// j = old_i;
	// }
	// assert(i < s.len && j < s.len);
	
	// 参考代码
	assert(s.len >= 0 && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = t;
	}
	assert(0 <= i && j <= s.len);
	
	text.len = j - i;
	text.str = s.str + i;
	
	return text;
}


T Text_put(const char *str){
	T text;
	
	assert(str);
	
	text.len = strlen(str);
	text.str = memcpy(Text_alloc(text.len), str, text.len);
	
	return text;
}


char *Text_get(char *str, int size, T s){
	assert(s.len >= 0 && s.str);
	
	if (str == NULL){
		str = ALLOC(s.len + 1);
	}
	else{
		assert(size >= s.len + 1);
	}
	
	memcpy(str, s.str, s.len);
	str[s.len] = '\0';
	
	return str;
}

/*
	memcpy		: 复制字符串，不复制末尾的空字符，但是会复制字符数组，中间的空字符
	str(n)cpy	: 复制字符串，会复制末尾的空字符，复制字符数组，不会复制中间的空字符，遇见空字符，即当做串尾，结束
	
	复制字符数组，使用memcpy()，复制字符串，使用str(n)cpy()
*/


T Text_dup(T s, int n){
	assert(s.len >= 0 && s.str);
	assert(n >= 0);
	
	// text_dup
	if (n == 0 || s.len == 0){
		return Text_null;
	}
	else if (n == 1){
		return s;
	}
	else{
		T text;
		char *p;
		
		text.len = n * s.len;
		if (isatend(s, text.len - s.len)){
			text.str = s.str;
			p = Text_alloc(text.len - s.len);
			n--;
		}
		else{
			text.str = p = Text_alloc(text.len);
		}
		
		for (; n-- > 0; p += s.len){
			memcpy(p, s.str, s.len);
		}
		
		return text;
	}
}


T Text_cat(T s1, T s2){
	assert(s1.len >= 0 && s1.str);
	assert(s2.len >= 0 && s2.str);
	
	// text_cat
	if (s1.len == 0){
		return s2;
	}
	if (s2.len == 0){
		return s1;
	}
	
	if (s1.str + s1.len == s2.str){
		s1.len += s2.len;
		return s1;
	}
	
	{
		T text;
		text.len = s1.len + s2.len;
		
		if (isatend(s1, s1.len)){
			text.str = s1.str;
			memcpy(Text_alloc(s2.len), s2.str, s2.len);
		}
		else{
			char *p;
			text.str = p = Text_alloc(text.len);
			memcpy(p, s1.str, s1.len);
			memcpy(p + s1.len, s2.str, s2.len);
		}
		
		return text;
	}
}


T Text_reverse(T s){
	assert(s.len >= 0 && s.str);
	
	if (s.len == 0){
		return Text_null;
	}
	else if (s.len == 1){
		return s;
	}
	else{
		T text;
		char *p;
		int i = s.len;
		
		text.len = s.len;
		text.str = p = Text_alloc(text.len);
		while (--i >= 0){
			*p++ = s.str[i];
		}
		
		return text;
	}
}


T Text_map(T s, const T *from, const T *to){
	static char map[256];
	static int inited = 0;
	
	assert(s.len >= 0 && s.str);
	
	if (from && to){
		// rebuild map
		int k;
		for (k = 0; k < (int)sizeof(map); k++){
			map[k] = k;
		}
		
		assert(from->len == to->len);
		
		for (k = 0; k < from->len; k++){
			map[ from->str[k] ] = to->str[k];
		}
		inited = 1;
	}
	else{
		assert(from == NULL && to == NULL);
		assert(inited);
	}
	
	if (s.len == 0){
		return Text_null;
	}
	else{
		T text;
		int i;
		char *p;
		
		text.len = s.len;
		text.str = p = Text_alloc(text.len);
		for (i = 0; i < s.len; i++){
			*p++ = map[s.str[i]];
		}
		
		return text;
	}
}


int Text_cmp(T s1, T s2){
	assert(s1.len >= 0 && s1.str);
	assert(s2.len >= 0 && s2.str);
	
	if (s1.str == s2.str){
		return s1.len - s2.len;
	}
	else if (s1.len < s2.len){
		int cond = memcmp(s1.str, s2.str, s1.len);
		return cond == 0 ? -1 : cond;
	}
	else if (s1.len > s2.len){
		int cond = memcmp(s1.str, s2.str, s2.len);
		return cond == 0 ? 1 : cond;
	}
	else{	// 等长度
		return memcmp(s1.str, s2.str, s1.len);
	}
}


Text_save_T Text_save(void){
	Text_save_T save;
	
	NEW(save);
	save->current = current;	// 全局current
	save->avail = current->avail;
	Text_alloc(1);
	
	return save;
}


void Text_restore(Text_save_T *save){
	struct chunk *p;
	struct chunk *q;
	
	assert(save && *save);
	
	current = (*save)->current;
	current->avail = (*save)->avail;
	FREE(*save);
	for (p = current->link; p; p = q){
		q = p->link;
		FREE(p);
	}
	current->link = NULL;
}


int Text_chr(T s, int i, int j, int c){
	// convert i and j to indices in 0...s len 
	assert(s.len >= 0 && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = t;
	}
	assert(0 <= i && j <= s.len);
	
	for (; i < j; i++){
		if (s.str[i] == c){
			return i + 1;
		}
	}
	
	return 0;
}


int Text_rchr(T s, int i, int j, int c){
	// convert i and j to indices in 0...s.len
	assert(s.len >= 0 && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = t;
	}
	assert(0 <= i && j <= str.len);
	
	while (i < j){
		if (s.str[--j] == c){
			return j + 1;
		}
	}
	
	return 0;
}


int Text_upto(T s, int i, int j, T set){
	assert(set.len >= 0 && set.str);
	
	// convert i and j to indices in 0...s.len
	assert(s.len >= 0 && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = t;
	}
	assert(0 <= i && j <= s.len);
	
	while (i < j){
		if (memchr(set.str, s.str[i++], set.len)){
			return i;
		}
	}
	
	return 0;
}


int Text_rupto(T s, int i, int j, T set){
	assert(set.len >= 0 && set.str);
	
	// convert i and j to indices in 0...set.str 
	assert(s.len >= 0 && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = t;
	}
	assert(0 <= i && j <= s.len);
	
	while (i < j){
		if (memstr(set.str, s.str[--j], set.len)){
			return j + 1;
		}
	}
	
	return 0;
}


int Text_find(T s, int i, int j, T str){
	assert(str.len >= 0 && str.str);
	
	// convert i and j to indices in 0...s.len 
	assert(s.len >= 0 && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = t;
	}
	assert(0 <= i && j < s.len);
	
	if (str.len == 0){
		return i + 1;
	}
	else if (str.len == 1){
		while (i < j){
			if (s.str[i++] == str.str[0]){
				return i;
			}
		}
	}
	else{
		while (i + str.len <= j){
			if (equal(s, i, str)){	// 宏命令 memcmp(s.str+i, str.str, str.len) == 0
				return i + 1;
			}
			i++;
		}
	}
	
	return 0;
}


int Text_rfind(T s, int i, int j, T str){
	assert(str.len >= 0 && str.str);
	
	// convert i and j to indices in 0...s.len 
	assert(s.len >= 0 && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = t;
	}
	assert(0 <= i && j < s.len);
	
	if (str.len == 0){
		return j + 1;
	}
	else if (str.len == 1){
		while (i < j){
			if (s.str[--j] == str.str[0]){
				return j + 1;
			}
		}
	}
	else{
		while (i <= j - str.len){
			if (equal(s, j-str.len, str)){	// 宏命令 memcmp(s.str+i, str.str, str.len) == 0
				return j - str.len + 1;
			}
			j--;
		}
	}
	
	return 0;
}


int Text_any(T s, int i, T set){
	assert(s.len >= 0 && s.str);
	assert(set.len >= 0 && set.str);
	
	i = idx(i, s.len);
	
	assert(0 <= i && i <= s.len);
	
	if (i < s.len && memchr(set.str, s.str[i], set.len)){
		return i + 2;
	}
	
	return 0;
}


int Text_many(T s, int i, int j, T set){
	assert(set.len >= 0 && set.str);
	
	// convert i and j to indices in 0...s.len
	assert(0 <= s.len && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = i;
	}
	assert(0 <= i && j <= s.len);
	
	if (i < j && memchr(set.str, s.str[i], set.len)){
		do{
			i++;
		} while (i < j && memchr(set.str, s.str[i], set.len));
		
		return i + 1;
	}
	
	return 0;
}


int Text_rmany(T s, int i, int j, T set){
	assert(set.len >= 0 && set.str);
	
	// convert i and j to indices in 0...s.len
	assert(0 <= s.len && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = i;
	}
	assert(0 <= i && j <= s.len);
	
	if (i < j && memchr(set.str, s.str[--j], set.len)){
		do{
			--j;
		} while (i <= j && memchr(set.str, s.str[j], set.len));
		
		return j + 2;
	}
	
	return 0;
}


int Text_match(T s, int i, int j, T str){
	assert(str.len >= 0 && str.str);
	
	// convert i and j to indices in 0...s.len
	assert(0 <= s.len && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = i;
	}
	assert(0 <= i && j <= s.len);
	
	if (str.len == 0){
		return i + 1;
	}
	else if (str.len == 1){
		if (i < j && s.str[i] == str.str[0]){
			return i + 2;
		}
	}
	else if ((i + str.len) <= j && equal(s, i, str)){
		return i + str.len + 1;
	}
	
	return 0;
}


int Text_rmatch(T s, int i, int j, T str){
	assert(str.len >= 0 && str.str);
	
	// convert i and j to indices in 0...s.len
	assert(0 <= s.len && s.str);
	i = idx(i, s.len);
	j = idx(j, s.len);
	if (i > j){
		int t = i;
		i = j;
		j = i;
	}
	assert(0 <= i && j <= s.len);
	
	if (str.len == 0){
		return j + 1;
	}
	else if (str.len == 1){
		if (i < j && s.str[--j] == str.str[0]){
			return i + 1;
		}
	}
	else if ((i + str.len) <= j && equal(s, j - str.len, str)){
		return j - str.len + 1;
	}
	
	return 0;
}


void Text_fmt(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	T *s;
	
	assert(app && flags);
	
	s = va_arg(*app, T *);
	assert(s && s->len >= 0 && s.str);
	
	Fmt_puts(s->str, s->len, put, c1, flags, width, precision);
}