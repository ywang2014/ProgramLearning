/**
	随机序列生成器
	
	C++
*/

std::vector<int> genKnuth(int n, int m){
	int select = m;
	int remaining = n;
	std::vector<int> v;
	
	for (int i = 0; i < n; i++){
		if ((rand() % remaining) < select){
			v.push_back(i);	// 选择i
			select--;
			/* 优化代码 */
				if (select == 0){
					break;
				}
		}
		remaining--;
	}
	
	return v;
}