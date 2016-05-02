/**
	使用C++标准模板库中的set模板，实现IntSet
*/
class IntSetSTL{
private:
	set<int> s;
public:
	IntSetSTL(int maxelements, int maxval){}
	int size(){ return s.size(); }
	void insert(int t){ s.insert(t); }
	void report(int *v){
		int i = 0;
		set<int>::iterator iter;
		for (iter = s.begin(); iter != s.end(); ++iter){
			v[i++] = *iter;
		}
	}
};