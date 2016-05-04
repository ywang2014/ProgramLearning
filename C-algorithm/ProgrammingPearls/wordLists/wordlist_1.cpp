/**
	生成文档中包含的单词列表
*/
#include <iostream>
#include <set>
#include <string>

int main(void){
	std::set<string> s;
	std::set<string>::iterator it;
	std::string str;
	
	while (std::cin >> str){
		s.insert(str);
	}
	for (it = s.begin(); it != s.end(); ++it){
		std::cout << *it << std::endl;
	}
	
	return 0;
}