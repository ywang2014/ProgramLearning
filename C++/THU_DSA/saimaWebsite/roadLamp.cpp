/**
	题目描述							
		V先生有一天工作到很晚，回家的时候要穿过一条长l的笔直的街道，这条街道上有n个路灯。假设这条街起点为0，终点为l，第i个路灯坐标为ai。路灯发光能力以正数d来衡量，其中d表示路灯能够照亮的街道上的点与路灯的最远距离，所有路灯发光能力相同。为了让V先生看清回家的路，路灯必须照亮整条街道，又为了节省电力希望找到最小的d是多少？
		
	输入
		输入两行数据，第一行是两个整数：路灯数目n (1≤n≤1000)，街道长度l (1 ≤l≤109)。第二行有n个整数ai (0 ≤ ai≤ l)，表示路灯坐标，多个路灯可以在同一个点，也可以安放在终点位置。
		
	输出
		输出能够照亮整个街道的最小d，保留两位小数。
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n = 0;
	int l = 0;
	while (cin >> n >> l){
		int *arr = new int[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(arr, arr+n);
		int diff = 0;
		for (int i = 1; i < n; i++){
			int newdiff = arr[i] - arr[i-1];
			diff = (diff < newdiff ? newdiff : diff);
		}
		if (diff < 2 * arr[0]){
            diff = 2 * arr[0];
		}
		if (diff < 2 * (l - arr[n-1])){
            diff = 2 * (l - arr[n-1]);
		}
        cout.precision(2);	// 保证输出2位小数 
		cout << fixed << diff / 2.0 << endl;	// fixed保证输出右边补零
	}
	return 0;
}