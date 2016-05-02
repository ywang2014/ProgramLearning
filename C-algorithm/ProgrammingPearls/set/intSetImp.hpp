/**
	整数集合 IntSet
*/
class IntSetImp{
public:
	IntSetImp(int maxelements, int maxval);
	void insert(int t);
	int size();
	void report(int *v);	// 将集合元素有序插入数组v中。
};