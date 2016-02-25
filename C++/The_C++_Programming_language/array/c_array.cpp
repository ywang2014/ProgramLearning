/**
	将数组封装，提供标准容器界面
*/
template<class T, int max>
struct c_array
{
	typedef T value_type;
	
	typedef T* iterator;
	typedef const T* const_iterator;
	
	typedef T& reference;
	typedef const T& const_reference;
	
	T v[max];
	operator T*()	// 转换函数，将数组，直接转化成指向其首元素地址的指针
	{
		return v;
	}
	
	reference operator[](size_t i) { return v[i]; }
	const_reference operator[](size_t i) const { return v[i]; }
	
	iterator begin() { return v; }
	const_iterator begin() const { return v; }
	
	iterator end() { return v+max; }
	const_iterator end() const { return v+max; }
	
	size_t size() const { return max; }
};

// test
void fn(int* p, int n);
void g()
{
	c_array<int, 10> a;	// 创建数组
	f(a, a.size());		// C风格，直接调用，普通数组一样
	c_array<int, 10>::iterator p = find(a.begin(), a.end(), 777);	// C++/STL模板风格使用
}