/**
	随机数生成序列
	集合操作法
*/
/*
	initialize set S to empty
	size = 0;
	while size < m do 
		t = rand() % n
		if t is not int s 
			insert t into s 
			size++;
*/
std::set<int> genSets(int m, int n){
	std::set<int> s;
	while (s.size() < m){
		s.insert(rand() % n);
	}
	
	return s;
}
