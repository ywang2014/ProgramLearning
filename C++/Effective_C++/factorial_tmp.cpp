/**
	模板元编程 TMP
	递归模板具体化
*/
template<unsigned n>
struct Factorial{
	enum{
		value = n * Factorial<n-1>::value
	};
};

template<>
struct Factorial<0>{
	enum{
		value = 1
	};
}