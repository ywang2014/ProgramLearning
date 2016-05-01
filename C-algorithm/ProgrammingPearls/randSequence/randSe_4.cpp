/**
	随机有序序列
	
	重新排序n个元素的数组，输出前m个元素
*/

std::vector<int> genShuf(int m, int n){
	std::vector<int> v;
	for (int i = 0; i < n; i++){
		v.push_back(i);
	}
	
	for (int i = 0; i < m; i++){	// 仅需要重新排序前m个元素即可
		int j = randint(i, n -1);
		swap(v[i], v[j]);
	}
	std::vector<int> res(v.begin(), v.begin() + m);
	sort(res.begin(), res.end());
	
	return res;
}