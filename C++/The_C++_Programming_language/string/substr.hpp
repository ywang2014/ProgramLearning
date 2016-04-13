/**
	substr 子串
*/
template<class Char_T, class Tr = cahr_traits<Char_T>, class A = allocator<Char_T> >
class basic_string{
	// ...
	
	// 子串定位
	void clear();
	basic_string substr(size_type i = 0, size_type n = npos) const;
	
	// ...
}


template<class Char_T> class Basic_substring{
public:
	typedef typename basic_string<Char_T>::size_type size_type;
	
	Basic_substring(basic_string<Char_T> &s, size_type i, size_type n);
	Basic_substring(basic_string<Char_T> &s, const basic_string<Char_T> &s2);
	Basic_substring(basic_string<Char_T> &s, const Char_T *p);
	
	Basic_substring &operator=(const basic_string<Char_T> &s);
	Basic_substring &operator=(const Basic_substring<Char_T> &s);
	Basic_substring &operator=(const Char_T* p);
	Basic_substring &operator(Char_T c);
	
	operator basic_string<Char_T>() const;
	operator const Char_T *() const;

private:
	basic_string<Char_T> *ps;
	size_type pos;
	size_type n;
};