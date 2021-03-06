/**
	题目描述
		学校联欢晚会的时候，为了使每一个同学都能参与进来，主持人常常会带着同学们玩击鼓传花的游戏。游戏规则是这样的：n个同学坐着围成一个圆圈，指定一个同学手里拿着一束花，主持人在旁边背对着大家开始击鼓，鼓声开始之后拿着花的同学开始传花，每个同学都可以把花传给自己左右的两个同学中的一个（左右任意），当主持人停止击鼓时，传花停止，此时，正拿着花没传出去的那个同学就要给大家表演一个节目。
		 聪明的小赛提出一个有趣的问题：有多少种不同的方法可以使得从小赛手里开始传的花，传了m次以后，又回到小赛手里。对于传递的方法当且仅当这两种方法中，接到花的同学按接球顺序组成的序列是不同的，才视作两种传花的方法不同。比如有3个同学1号、2号、3号，并假设小赛为1号，花传了3次回到小赛手里的方式有1->2->3->1和1->3->2->1，共2种。
										
	输入
		输入共一行，有两个用空格隔开的整数n，m（3<=n<=30，1<=m<=30）
	输出
		输出共一行，有一个整数，表示符合题意的方法数
		
	例：输入3 3，输出2
*/
#include <iostream>

using namespace std;

int main(){
	int n = 0;
	int m = 0;
	while (cin >> n >> m){
		int *arr = new int[n];
		int *arr2 = new int[n];
		for (int i = 0; i < n; i++){
			arr[i] = 0;
			arr2[i] = 0;
		}
		arr[0] = 1;
		int flag = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				// 必须分两个数组，否则：后面的点会计算前面刚刚更新的点(冗余)
				if (flag == 0){
					arr2[j] = arr[((j-1 + n) % n)] + arr[((j+1) % n)];
				}
				else {
					arr[j] = arr2[((j-1 + n) % n)] + arr2[((j+1) % n)];
				}
			}
			flag = 1 - flag;	// 赋值完后，flag更新了，所以flag刚好相反！
		}
		if (flag == 1){
			cout << arr2[0];
		}
		else{
			cout << arr[0];
		}
		
	}
	return 0;
}
