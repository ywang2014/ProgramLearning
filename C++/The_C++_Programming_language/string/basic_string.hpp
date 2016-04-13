/**
	basic_string 基础串类
*/
template<class Char_T, class Tr = char_traits<Char_T>, class A = allocator<Char_T> >
class std::basic_string{
public:
	// 类型成员
	typedef Tr traits_type;
	
	typedef typename Tr::char_type value_type;
	typedef A allocator_type;
	typedef typename A::size_type size_type;
	typedef typename A::difference_type difference_type;
	
	typedef typename A::reference reference;
	typedef typename A::const_reference const_reference;
	typedef typename A::pointer pointer;
	typedef typename A::const_pointer const_pointer;
	
	typedef implementation_defined iterator;
	typedef implementation_defined const_iterator;
	
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef atd::reverse_iterator<const_iterator> const_reverse_iterator;
	
	// 迭代器
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	
	// 元素访问
	const_reference operator[](size_type n) const;	// 不带检查的访问
	reference operator[](size_type n);
	
	const_reference at(size_type n) const;	// 带检查的访问
	reference at(size_type n);
	
	// 构造函数  (string不能使用字符或者整数去初始化)
	explicit basic_string(const A &a = A());
	basic_string(const basic_string &s, size_type pos = 0, size_type n = npos, const A& a = A());
	basic_string(const Char_T *p, size_type n, const A &a = A());
	basic_string(const Char_T *p, const A &a = A());
	basic_string(size_type n, Char_T c, const A &a = A());
	template<class In> basic_string(In first, In last, const A &a = A());
	
	~basic_string();
	
	static const size_type npos;	// 表示“所有字符”
	
	// 赋值
	basic_string &operator=(const basic_string &s);
	basic_string &operator=(const Char_T *p);
	basic_string &operator=(Char_T c);	// 字符不能用于构造函数，但是可以用于赋值
	
	basic_string &assign(const basic_string &);
	basic_string &assign(const basic_string &s, size_type pos, size_type n);
	basic_string &assign(const Char_T *p, size_type n);
	basic_string &assign(const Char_T *p);
	basic_string &assign(size_type n, Char_T c);
	template<class In> basic_string &assign(In first, In last);
	
	// 到C风格字符串的转换
	const Char_T *c_str() const;
	const Char_T *data() const;
	size_type copy(Char_T *p, size_type n, size_type pos = 0) const;
	
	// 比较函数
	int compare(const basic_string &s) const;
	int compare(const Char_T *p) const;
	
	int compare(size_type pos, size_type n, const basic_string &s) const;
	int compare(size_type pos, size_type n, const basic_string &s, size_type pos2, size_type n2) const;
	int compare(size_type pos, size_type n, const Char_T *p, size_type n2 = npos) const;
	
	// 插入
	basic_string &operator+=(const basic_string &s);
	basic_string &operator+=(const Char_T *p);
	basic_string &operator+=(Char_T c);
	
	void push_back(Char_T c);
	
	basic_string &append(const basic_string &s);
	basic_string &append(const basic_string &s, size_type pos, size_type n);
	basic_string &append(const Char_T *p, size_type n);
	basic_string &append(const Char_T *p);
	basic_string &append(size_type n, Char_T c);
	template<class In> basic_string &append(In first, In last);
	
	// 在(*this)[pos]之前添加字符
	basic_string &insert(size_type pos, const basic_string &s);
	basic_string &insert(size_type pos, const basic_string &s, size_type pos2, size_type n);
	basic_string &insert(size_type pos, const Char_T *p, size_type n);
	basic_string &insert(size_type pos, const Char_T *p);
	basic_string &insert(size_type pos, size_type n, Char_T c);
	
	// 在p之前添加字符
	iterator insert(iterator p, Char_T c);
	void insert(iterator p, size_type n, Char_T c);
	template<class In> void insert(iterator p, In first, In last);
	
	// 查找子串
	size_type find(const basic_string &s, size_type i = 0) const;
	size_type find(const Char_T *p, size_type i, size_type n) const;
	size_type find(const Char_T *p, size_type i = 0) const;
	size_type find(Char_T c, size_type i = 0) const;
	
	size_type rfind(const basic_string &s, size_type i = npos) const;
	size_type rfind(const Char_T *p, size_type i, size_type n) const;
	size_type rfind(const Char_T *p, size_type i = npos) const;
	size_type rfind(Char_T c, size_type i = npos) const;
	
	size_type find_first_of(const basic_string &s, size_type i = 0) const;
	size_type find_first_of(const Char_T *p, size_type i, size_type n) const;
	size_type find_first_of(const Char_T *p, size_type i = 0) const;
	size_type find_first_of(Char_T c, size_type i = 0) const;
	
	size_type find_last_of(const basic_string &s, size_type i = npos) const;
	size_type find_last_of(const Char_T *p, size_type i, size_type n) const;
	size_type find_last_of(const Char_T *p, size_type i = npos) const;
	size_type find_last_of(Char_T c, size_type i = npos) const;
	
	size_type find_first_not_of(const basic_string &s, size_type i = 0) const;
	size_type find_first_not_of(const Char_T *p, size_type i, size_type n) const;
	size_type find_first_not_of(const Char_T *p, size_type i = 0) const;
	size_type find_first_not_of(Char_T c, size_type i = 0) const;
	
	size_type find_last_not_of(const basic_string &s, size_type i = npos) const;
	size_type find_last_not_of(const Char_T *p, size_type i, size_type n) const;
	size_type find_last_not_of(const Char_T *p, size_type i = npos) const;
	size_type find_last_not_of(Char_T c, size_type i = npos) const;
	
	// 替代
	basic_string &replace(size_type i, size_type n, const basic_string &s);
	basic_string &replace(size_type i, size_type n, const basic_string &s, size_type i2, size_type n2);
	basic_string &replace(size_type i, size_type n, const Char_T *p, size_type n2);
	basic_string &replace(size_type i, size_type n, const Char_T *p);
	basic_string &replace(size_type i, size_type n, size_type n2, Char_T c);
	
	basic_string &replace(iterator i, iterator i2, const basic_string &s);
	basic_string &replace(iterator i, iterator i2, const Char_T *p, size_type n);
	basic_string &replace(iterator i, iterator i2, const Char_T *p);
	basic_string &replace(iterator i, iterator i2, size_type n, Char_T c);
	template<class In> basic_string &replace(iterator i, iterator i2, In j, In j2);
	
	// 从串中删除("用空串替换")
	basic_string &erase(size_type i = 0; size_type n = npos);
	iterator erase(iterator i);
	iterator erase(iterator first, iterator last);
	
	
	// 大小，容量
	size_type size() const;
	size_type max_size() const;
	size_type length() const {
		return size();
	}
	bool empty() const{
		return size() == 0;
	}
	
	void resize(size_type n, Char_T c);
	void resize(size_type n){
		resize(n, Char_T());
	}
	
	size_type capacity() const;
	void reserve(size_type res_arg = 0);
	
	allocator_type get_allocator() const;
};

typedef basic_string<char> string;
typedef basic_string<wchar_t> wstring;


// 比较运算符
template<class Char_T, class Tr, class A>
bool operator==(const basic_string<Char_T, Tr, A> &s1, const basic_string<Char_T, Tr, A> &s2);

template<class Char_T, class Tr, class A>
bool operator==(const Char_T *str, const basic_string<Char_T, Tr, A> &s2);

template<class Char_T, class Tr, class A>
bool operator==(const basic_string<Char_T, Tr, A> &s1, const Char_T *str);

// != > < >= <= 如此类似


// 拼接
template<class Char_T, class Tr, class A>
basic_string<Char_T, Tr, A>
operator+(const basic_string<Char_T, Tr, A> &s, const basic_string<Char_T, Tr, A> &s2);

template<class Char_T, class Tr, class A>
basic_string<Char_T, Tr, A>
operator+(const Char_T *str, const basic_string<Char_T, Tr, A> &s);

template<class Char_T, class Tr, class A>
basic_string<Char_T, Tr, A>
operator+(const basic_string<Char_T, Tr, A> &s, const Char_T *str);

template<class Char_T, class Tr, class A>
basic_string<Char_T, Tr, A>
operator+(Char_T ch, const basic_string<Char_T, Tr, A> &s);

template<class Char_T, class Tr, class A>
basic_string<Char_T, Tr, A>
operator+(const basic_string<Char_T, Tr, A> &s, Char_T ch);

// I/O操作
template<class Char_T, class Tr, class A>
basic_istream<Char_T, Tr> &operator>>(basic_istream<Char_T, Tr) &bis, basic_string<Char_T, Tr, A> &s);

template<class Char_T, class Tr, class A>
basic_ostream<Char_T, Tr> &operator<<(basic_ostream<Char_T, Tr> &bis, const basic_string<Char_T, Tr, A> &s);

template<class Char_T, class Tr, class A>
basic_istream<Char_T, Tr> &getline(basic_istream<Char_T, Tr> &bis, basic_string<Char_T, Tr, A> &s, Char_T eol);

template<class Char_T, class Tr, class A>
basic_istream<Char_T, Tr> &getline(basic_istream<Char_T, Tr> &bis, basic_string<Char_T, Tr, A> &s);

template<class Char_T, class Tr, class A>
void swap(basic_string<Char_T, Tr, A> &s1, basic_string<Char_T, Tr, A> &s2);