/**
	优先队列 priority queue
*/
template<class T> class priqueue{
private:
	int n;
	int maxsize;
	T *multiset;	// 允许重复值
	
	void siftup(int pos);
	void siftdown(int pos);

public:
	priqueue(int maxsize);	// init multiset s to empty 
	void insert(T t);		// add t to s
	T extractmin();			// return smallest in s 
};