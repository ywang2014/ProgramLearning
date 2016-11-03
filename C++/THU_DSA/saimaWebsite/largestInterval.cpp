/**

	题目描述					
		给定一个递增序列，a1＜a2＜…＜an。定义这个序列的“最大间隔”为            
		现在要从a2,a3...an-1中删除一个元素，问剩余序列的“最大间隔”最小是多少？
						
	输入
		第一行，一个正整数n（1＜=n＜=100），序列长度。
		接下来n个小于1000的正整数，表示一个递增序列。
	输出
		一个数d表示从a2,a3...an-1中删除一个元素后“最大间隔”的最小值。
		
	分析：由于只能删除a2,a3...an-1中的一个，所以不需要考虑删除a1和an的情况，直接计算隔一个的两个数之间的差值即可
*/
#include <iostream>

using namespace std;

int main(){
	int n = 0;
	while (cin >> n){
		int *arr = new int[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}

		int min2 = 1000;
		int index = 0;
		for (int i = 2; i < n; i++){
			int diff = arr[i] - arr[i-2];
			if (min2 > diff){
				min2 = diff;
				index = i - 1;
			}
		}

		int max2 = 0;
		for (int i = 1; i < n; i++){
			int diff = arr[i] - arr[i-1];
			if (i == index){
				diff = arr[i+1] - arr[i-1];
			}
			max2 = (max2 < diff ? diff : max2);
		}
		cout << max2 << endl;
	}

	return 0;
}
