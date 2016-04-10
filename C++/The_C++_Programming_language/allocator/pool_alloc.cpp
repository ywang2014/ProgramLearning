#include "pool_alloc.h"

template<class T> 
T *Pool_alloc<T>::allocate(size_type n, void * = 0){
	if (n == 1){
		return static_cast<T *>(mem.alloc());
	}
	// ...
}

template<class T>
void Pool_alloc<T>::deallocate(pointer p, size_type n){
	if (n == 1){
		mem.free(p);
		return ;
	}
	// ...
}


// test
vector<int, Pool_alloc<int> > v;
map<string, number, Pool_alloc<pair<const string, number> > > m;

vector<int> v2 = v;	// 错误，使用的分配器不同，故类型不同