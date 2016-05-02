/**
	借助接口的随机序列实现
*/
#include "intSetImp.hpp"

void gensets(int m, int maxval){
	int *v = new int[m];
	IntSetImp S(m, maxval);
	while (S.size() < m){
		S.insert(bigrand() % maxval);
	}
	S.report(v);
	for (int i = 0; i < m; i++){
		cout << v[i] << "\n";
	}
	
	delete []v;
}