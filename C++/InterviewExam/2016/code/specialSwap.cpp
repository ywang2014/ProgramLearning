/**	
	特殊交换
	现有一个n个整数的序列，你要做的就是交换两个数的位置直到整个序列按照升序排列，那么将这个整数序列排好序，需要交换多少次？
	例如，1，2，3，5，4，我们只需要交换一次，即将5和4交换即可。

	输入描述:
	第一行输入一个正整数n（n≤1000），表示数字序列的元素个数，占一行；接下来一行输入从1到n的n个整数排序，中间用空格隔开


	输出描述:
	输出序列升序排列需要的最少交换次数

	输入例子:
	4
	4 3 2 1

	输出例子:
	6
	
	本质就是逆序对数
*/
int swapNums(int *arr, int n){
	int count = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (arr[i] > arr[j]){
				count++;
			}
		}
	}
	
	return count;
}


int main(){
	int n = 0;
	while (cin >> n){
		int *nums = new int[n];
		for (int i = 0; i < n; i++){
			cin >> nums[i];
		}
		
		cout << swapNums(nums, n) << endl;
		delete [] nums;
	}
	
	return 0;
}

/********************************************/
#include <iostream>

using namespace std;

int swapNums(int *arr, int n){
	int count = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (arr[i] > arr[j]){
				count++;
			}
		}
	}
	
	return count;
}


int main(){
	int n = 0;
	while (cin >> n){
		int *nums = new int[n];
		for (int i = 0; i < n; i++){
			cin >> nums[i];
		}
		
		cout << swapNums(nums, n) << endl;
		delete [] nums;
	}
	
	return 0;
}

// AC