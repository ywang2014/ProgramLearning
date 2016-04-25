/**
	apply()
	
	valarry()中的成员函数，变成非成员函数，接收函数对象
*/

template<typename T>
valarray<T> apply(T f(T ), const valarray<T> &v){
	assert(v != NULL && f != NULL);
	
	auto len = v.size(); 
	valarray<T> val(len);
	for (int i = 0; i < len; i++){
		val[i] = f(v[i]);
	}
	
	return val;
}