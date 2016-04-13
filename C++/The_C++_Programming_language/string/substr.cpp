/**
	substring 部分函数实现
*/
template<class Char_T>
Basic_substring<Char_T>::Basic_substring(basic_string<Char_T> &s, const basic_string<Char_T> &s2)
	: ps(&s), n(s2.length()) {
	pos = s.find(s2);
}

template<class Char_T>
Basic_substring<Char_T> &Basic_substring<Char_T>::operator=(const basic_string<Char_T> &s){
	ps->replace(pos, n, s);	// 通过 *ps写
	
	return *this;
}

template<class Char_T> Basic_substring<Char_T>::operator basic_string<Char_T>() const{
	return basic_string<Char_T>(*ps, pos, n);	// 从*ps复制
}