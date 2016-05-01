/**
	Bob Floyd 集合算法
*/
std::set<int> genFloyd(int m, int n){
	std::set<int> s;
	std::set<int>::iterator it;
	
	for (int j = n - m; j < n; j++){
		int t = bigrand() % (j + 1);
		if (s.find(t) == s.end()){
			s.insert(t);
		}
		else{	// 随机次数不变，随机数失败，直接插入即可
			s.insert(j);
		}
	}
}