/**
	实现一个队列的入队和出队方法
	要求：
		1.输入数据有三种优先级
		2.出队实现两种出队方式：
			1.忽略优先级出队，所有数据根绝先进先出的方式出队
			2.根据优先级出队，高优先级的先出队列，同一优先级的，先进先出。
*/
struct T{
	int elem;
	int level;
};

class SpecailQueue<T>{
	T *que;
	T *que_high;
	T *que_medium;
	T *que_low;
	int front;
	int rear;
	int f_h;
	int r_h;
	int f_m;
	int r_m;
	int f_l;
	int r_l;
	int N;	// 队列的基础容量
	
public:
	explicit SpecailQueue<T>(int n){
		N = n;
		que_low = new T[N];
		que_medium = new T[N];
		que_high = new T[N];
		
		front = f_h = f_m = f_l = -1;
		rear = r_h = r_m = r_l = 0;
	}
	
	SpecailQueue<T>(){
		SpecailQueue<T>(16);
	}
	
	void enqueue(T elem){
		if (rear < 3*N){
			que[rear++] = elem;
		}
		
		if (elem.level == 3){
			if (r_h < N){
				que_high[r_h++] = elem;
			}
		}
		else if (elem.level == 2){
			if (r_m < N){
				que_medium[r_m++] = elem;
			}
		}
		else if (elem.level == 1){
			if (r_l < N){
				que_low[r_l++] = elem;
			}
		}
		
		// 队列满了，需要扩容
	}
	
	T dequeu(){
		if (front < rear-1){
			return que[++front];
		}
		// 空队列
	}
	
	T dequeueByPriority(){
		if (f_h < r_h - 1){
			return que_high[++f_h];
		}
		else if (f_m < r_m - 1){
			return que_medium[++f_m];
		}
		else if (f_l < r_l - 1){
			return que_low[++f_l];
		}
		
		// 空队列
		// 需要维护que中的元素出队列，比较麻烦 ---  搜索一遍这个que，删除这个elem即可！
	}
}