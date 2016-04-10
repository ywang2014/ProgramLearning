/**
	Pool_alloc interface
	
	依据Pool实现的分配器
*/
#include "pool.h"

template<typename T>
class Pool_alloc{
private:
	static Pool mem;	// sizeof(T)的元素池

public:
	// 标准分配器(19.4.1)
	
};

template<class T> Pool Pool_alloc<T>::mem(sizeof(T));
template<class T> Pool_alloc<T>::Pool_alloc(){}