/**
	http://exercise.acmcoder.com/
	
	翻转数组
	题目描述
		给定一个长度为n的整数数组a，元素均不相同，问数组是否存在这样一个片段，只将该片段翻转就可以使整个数组升序排列。其中数组片段[l,r]表示序列a[l], a[l+1], ..., a[r]。原始数组为
		a[1], a[2], ..., a[l-2], a[l-1], a[l], a[l+1], ..., a[r-1], a[r], a[r+1], a[r+2], ..., a[n-1], a[n]，
		将片段[l,r]反序后的数组是
		a[1], a[2], ..., a[l-2], a[l-1], a[r], a[r-1], ..., a[l+1], a[l], a[r+1], a[r+2], ..., a[n-1], a[n]。
	输入
		第一行数据是一个整数：n (1≤n≤105)，表示数组长度。
		第二行数据是n个整数a[1], a[2], ..., a[n] (1≤a[i]≤109)。
	输出
		输出“yes”，如果存在；否则输出“no”，不用输出引号。
*/

#include <iostream>

using namespace std;

int main(){
	int n = 0;
	static int arr[100000];
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		int l = 0;
		bool res = false;
		for (int i = 1; i < n; i++){
			if (arr[i] < arr[i-1]){
				if (l == 0){
					l = i;
				}
				if (res){
					res = false;
					break;
				}
			}
			else if (l != 0){
				res = true;
			}
		}
		if (res){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
	
	return 0;
}

void isYes(int *arr, int n){  // 86%
	bool isreverse = false;
	bool res = false;
	for (int i = 1; i < n; i++){
		if (arr[i] < arr[i-1]){
			isreverse = true;
			if (res){
				res = false;
				break;
			}
			if (i == n-1){
			   res = true;
			}
		}
		else if (isreverse){
			res = true;
		}
	}
	if (n < 3 || res || !isreverse){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
}

#include <algorithm>

void isYes(int *arr, int n){
	int ordered[100000];
	for (int i = 1; i < n; i++){
		ordered[i] = arr[i];
	}
  	sort(ordered, ordered + n);
	
	int lo = 0;
  	// while (lo < n && arr[lo] == ordered[lo++]); // 不行
  	while (lo < n && arr[lo] == ordered[lo]) lo++;
	int hi = n - 1;
	while (hi >= 0 && arr[hi] == ordered[hi--]) // 不行
	while (hi >= 0 && arr[hi] == ordered[hi]) hi--;
	
	bool res = true;
	while (lo < hi){
		if (arr[lo++] != ordered[hi--]){	// 可以
			res = false;
			break;
		}
	}
	if (res){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
}

//////////////////////////////////////////////////////
											
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int arr[100010];
	int ordered[100010];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		ordered[i] = arr[i];
	}
	sort(ordered, ordered + n);
	
	int start = 0, end = n - 1;
	while(start < n && arr[start] == ordered[start])start++;
	while(end >= 0 && arr[end] == ordered[end])end--;
	bool res = true;
	while(start < end){
		if(ordered[start] != arr[end]){
			res = false;
			break;
		}
		start++, end--;
	}
	if(res){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
		
	return 0;
}
