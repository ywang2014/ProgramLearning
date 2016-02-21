/**
	协助函数
*/

// 比较vector的大小
template <class T, class A>
	bool std::operator==(const vector<T, A>& x, const vector<T, A>& y);
	
template <class T, class A>
	bool std::operator<(const vector<T, A>& x, const vector<T, A>& y);
	
// 专门化定义
template <class T, class A>
	void std::swap(vector<T, A>& x, vector<T, A>& y) { x.swap(y); }
	
