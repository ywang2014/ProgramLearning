/**
	字符特征类 char_traits
*/
template<class Char_T> struct char_traits{};

// char_traits操作不应抛出异常
template<> struct char_traits<char>{
	typedef char char_type;
	static void assign(char_type&, const char_type&);	// =
	
	typedef int int_type;
	
	static char_type to_char_type(const int_type&);
	static int_type to_int_type(const char_type&);
	static bool eq_int_type(const int_type&, const int_type&);	// ==
	
	static bool eq(const char_type&, const char_type&);
	static bool lt(const char_type&, const char_type&);	// less than
	
	// 从s2复制n个字符到s中
	static char_type *move(char_type *s, const char_type *s2, size_t n);	// 可处理重叠情况
	static char_type *copy(char_type *s, const char_type *s2, size_t n);	// 速度快
	static char_type *assign(char_type *s, size_t n, char_type a);
	
	static int compare(const char_type *s, const char_type *s2, size_t n);
	static size_t length(const char_type *);
	static const char_type *find(const char_type *s, int n, const char_type &);
	
	typedef streamoff off_type;		// 流中的偏移量
	typedef streampos pos_type;
	typedef mbstate_t state_type;	// 多字节流状态
	
	static int_type eof();
	static int_type not_eof(const int_type &i);	// i不等于eof()，则为i，否则返回任何非eof()值
	static state_type get_state(pos_type p);	// p中字符的多字节转换状态
};