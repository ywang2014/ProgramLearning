/**
	变位词程序
	
	sort程序，将相同签名的单词，全部整理在一起
	
	利用C++语言实现
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class wordBag{
	string sig;
	string word;
public:
	wordBag(){
		sig = "";
		word = "";
	}
	
	wordBag(string s, string w){
		sig = s;
		word = s;
	}
	
	~wordBag(){}
	
	int cmp(const wordBag& w){
		return sig.compare(w.sig)
	}
	
	friend ostream& operator<<(ostream &os, wordBag &w){
		os << w.sig << " " << w.word;
		
		return os;
	}
};

int cmp(const wordBag &a, const wordBag &b){
	// if (a.sig < b.sig){
		// return -1;
	// }
	// else if (a.string == b.string){
		// return 0;
	// }
	
	// return 1;
	// return a.sig.compare(b.sig);	// 私有变量无法访问
	return a.cmp(b);
}

int main(void){
	vector<wordBag> dic;
	
	while (scanf("%s %s", sig, word) != EOF){
		dic.push_back(wordBag(sig, word));
	}
	
	sort(dic.begin(), dic.end(), cmp);
	
	typedef vector<wordBag>::iterator IT;
	for (IT index = dic.begin(); index != dic.end(); ++index){
		cout << *index << endl;
	}
	
	return 0;
}