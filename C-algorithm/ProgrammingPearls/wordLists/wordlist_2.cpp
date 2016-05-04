/**
	生成文档中包含的单词列表
	
	从文件输入，从文件输出
*/
#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main(void){
	set<string> s;
	set<string>::iterator it;
	string str;
	
	ifstream fin("book.txt");	// 构造函数自动调用 open()函数
	ofstream fout("dic.txt");
	
	cout << "reading begin...\n";
	if (fin.is_open()){
		while (!fin.eof()){
			fin >> str;
			s.insert(str);
		}
		fin.close();
	}
	
	cout << "writing begin...\n";
	if (fout.is_open()){
		for (it = s.begin(); it != s.end(); ++it){
			fout << *it << endl;
		}
		fout.close();
	}
	
	return 0;
}