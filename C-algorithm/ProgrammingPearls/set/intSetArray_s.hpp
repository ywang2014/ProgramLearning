/**
	查找类的实现完整代码
*/
class IntSetArray{
private:
	int n;
	int *arr;

public:
	IntSetArray(int maxelems, int maxval){
		arr = new int[1 + maxelems];
		n = 0;
		arr[0] = maxval;
	}
	
	int size(){ return n; }
	
	void insert(int t){
		int i;
		for (i = 0; arr[i] < t; i++){
			;
		}
		if (arr[i] == t){
			return ;
		}
		for (int j = n; j >= i; j--){	// n为哨兵
			arr[j+1] = arr[j];
		}
		arr[i] = t;
		n++;
	}
	
	void report(int *v){
		for (int i = 0; i < n; i++){
			v[i] = arr[i];
		}
	}
};