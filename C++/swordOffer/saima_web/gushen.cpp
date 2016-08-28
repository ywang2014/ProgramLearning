/**
	http://exercise.acmcoder.com/
	
	题目描述
		有股神吗？
		有，小赛就是！
		经过严密的计算，小赛买了一支股票，他知道从他买股票的那天开始，股票会有以下变化：第一天不变，以后涨一天，跌一天，涨两天，跌一天，涨三天，跌一天...依此类推。
		为方便计算，假设每次涨和跌皆为1，股票初始单价也为1，请计算买股票的第n天每股股票值多少钱？
*/

#include <iostream>

using namespace std;

int getPrice(int n){
	int price = 1;
	int up = 1;
	bool flag = true;
	
	while (n > 1){
		if (flag){
			if (n > up){
				price += up;
				flag = false;
				n -= up;
				up++;
			}
			else{
				price += n - 1;
				break;
			}
		}
		else{
			price --;
			flag = true;
			n--;
		}
	}
	return price;
}

int main(){
	int n = 0;
	while (cin >> n){
		cout << getPrice(n) << endl;
	}
	
	return 0;
}