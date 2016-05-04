/**
	生成文档中包含的单词列表
	
	统计单词出现的次数
*/
#include <iostream>
#include <map>
#include <string>

int main(void){
	std::map<string, int> m;
	std::map<string, int>::iterator it;
	std::string str;
	
	while (std::cin >> str){
		m[str]++;
	}
	for (it = m.begin(); it != m.end(); ++it){
		std::cout << it->first << " " << it->second << std::endl;
	}
	
	return 0;
}