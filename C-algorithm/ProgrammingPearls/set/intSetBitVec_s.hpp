/**
	查找类的实现完整代码
*/
class IntSetBitVec{
private:
	enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1f };
	int n;
	int *arr;
	int hi;
	
	void set(int i){ arr[i >> SHIFT] |= (1 << (i & MASK)); }
	void clr(int i){ arr[i >> SHIFT] &= ~(1 << (i & MASK)); }
	int test(int i){ return x[i >> SHIFT] & (1 << (i & MASK)); }
	
public:
	IntSetBitVec(int maxelems, int maxval){
		hi = maxval;
		arr = new int[1 + hi / BITSPERWORD];
		for (int i = 0; i < hi; i++){
			clr(i);
		}
		n = 0;
	}
	
	int size(){ return n; }
	
	void insert(int t){
		if (test(t)){
			return ;
		}
		set(t);
		n++;
	}
	
	void report(int *v){
		int index = 0;
		for (int i = 0; i < hi; i++){
			if (test(i)){
				v[index++] = i;
			}
		}
	}
};