/**
	题目描述								
		判断字符串b的所有字符是否都在字符串a中出现过，a、b都是可能包含汉字的字符串。b中重复出现的汉字，那么a中也要至少重复相同的次数。汉字使用gbk编码（简单的说，用两个字节表示一个汉字，高字节最高位为1的代表汉字，低字节最高位可以不为1）。
				int is_include(char *a, char *b); 
		  返回0表示没有都出现过，返回1表示都出现过。 
		请设计一个算法。
								
	输入
		字符串a\n字符串b
		样例输入
		aaaabbbcccdddss
		abc
	输出
		0或者1
		
	分析：
		既然汉字是由两个字节组成的，可以直接理解为两个独立的字符
		问题：两个独立的字符，可能会碰撞，不再是唯一的。
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	string stra;
	string strb;
	while (cin >> stra >> strb){
		int arr[256] = {0};
		for (int i = 0; i < strb.length(); i++){
			char ch = strb[i];
			arr[ch]++;
		}
		for (int i = 0; i < stra.length(); i++){
			char ch = stra[i];
			arr[ch]--;
		}
		
		int flag = 1;
		for (int i = 0; i < 256; i++){
			if (arr[i] > 0){
				flag = 0;
			}
		}
		cout << flag << endl;
	}
	
	return 0;
}

int is_include(char *a, char *b){
	int arr[256] = {0};
	while (*b != '\0'){
		arr[*b]++;
		b++;
	}
	while (*a != '\0'){
		arr[*a]--;
		a++;
	}
	
	for (int i = 0; i < 256; a++){
		if (arr[i] > 0){
			return 0;
		}
	}
	
	return 1;
}