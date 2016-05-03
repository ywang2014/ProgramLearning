/**
	优先队列实现代码
*/
#include "priorityQueue.hpp"

template<typename T>
void priqueue<T>::insert(T t){
	if (n >= maxsize){
		throw new Exception("range error!");
	}
	multiset[++n] = t;
	siftup(n);
}

template<typename T>
int priority<T>::extractmin(){
	if (n < 1){
		throw new Exception("range error!");
	}
	int mindata = multiset[1];
	multiset[1] = multiset[n--];
	siftdown(n);
	
	return mindata;
}