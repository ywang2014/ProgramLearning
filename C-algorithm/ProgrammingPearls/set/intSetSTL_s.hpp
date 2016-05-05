/**
	查找类的实现完整代码
*/
class IntSetSTL{
private:
	set<int> s;

public:
	IntSetSTL(int maxelems, int maxval){}
	int size(){ return s.size(); }
	void insert(int t){ s.insert(t); }
	void report(int *v){
		int index = 0;
		set<int>::iterator it;
		for (it = s.begin(); it != s.end(); ++it){
			v[index++] = *i;
		}
	}
};