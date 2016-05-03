/**
	优先队列的完整实现
*/
template<class T>
class priqueue{
private:
	int n;
	int maxsize;
	T *x;
	
	void swap(int first, int second){
		T t = x[first];
		x[first] = x[second];
		x[second] = t;
	}
	
public:
	priqueue(int m){
		maxsize = m;
		x = new T[maxsize + 1];
		n = 0;
	}
	
	~priqueue(){
		delete [] x;
	}
	
	void insert(T t){
		if (n < maxsize){
			x[++n] = t;
			for (int i = n; i > 1 && x[i/2] > x[i]; i = i / 2){
				swap(i/2, i);
			}
		}
		else{
			throw new Exception("over range!");
		}
	}
	
	T extractmin(){
		T mindata = x[1];
		x[1] = x[n--];
		
		int child = 2 * 1;	// 不能使用i
		for (int i = 1; child <= n; i = child, child = 2 * i){
			if (child + 1 <= n && x[child + 1] < x[child]){
				child++;
			}
			if (x[i] > x[child]){
				swap(child, i);
			}
			else{
				break;
			}
		}
		
		return mindata;
	}
};