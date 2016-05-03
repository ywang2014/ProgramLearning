/**
	优先队列实现排序算法
*/	
template<class T>
void priqueue_sort(T v[], int n){
	priqueue<T> pq(n);	// 创建优先级队列
	for (int i = 0; i < n; i++){
		pq.insert(v[i]);	// 创建一个快速建堆的构造函数
	}
	for (int i = 0; i < n; i++){
		v[i] = pq.extractmin();
	}
}