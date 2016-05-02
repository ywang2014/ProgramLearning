/**
	整型数组的实现 -- 线性结构
*/
class IntSetArray{
private:
	int n;
	int *x;
public:
	IntSetArray(int maxelements, int maxval){
		x = new int[maxelements + 1];
		n = 0;
		x[0] = maxval;
	}
	
	int size() const { return n; }
	
	void insert(int t){
		for (int i = 0; x[i] < t; i++){
			;
		}
		if (x[i] == t){
			return ;
		}
		for (int j = n; j >= i; j--){
			x[j + 1] = x[j];
		}
		x[i] = t;
		n++;
	}
	
	void report(int *v){
		for (int i = 0; i < n; i++){
			v[i] = x[i];
		}
	}
};