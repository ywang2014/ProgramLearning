/**
	跳石板
		小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
		这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
		例如：
		N = 4，M = 24：
		4->6->8->12->18->24
		于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板 
	
	输入描述:
		输入为一行，有两个整数N，M，以空格隔开。
		(4 ≤ N ≤ 100000)
		(N ≤ M ≤ 100000)
	输出描述:
		输出小易最少需要跳跃的步数,如果不能到达输出-1
	输入例子:
		4 24
	输出例子:
		5
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> getDivisor(int n){
	vector<int> divisor;
	for(int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			divisor.push_back(i);
			// int other = n / i;
			// if (i != other){
				// divisor.push_back(other);
			// }
			divisor.push_back(n / i);
		}
	}
	return divisor;
}

int getSteps(int n, int m){
	if (4 > n || n > 100000 || n > m || m > 100000){
		return -1;
	}
	
	int steps = m - n + 1;
	int *step = new int[steps];
	for (int i = 1; i < steps; i++){
		step[i] = m;
	}
	step[0] = 0;
	
	for (int i = n; i <= m; i++){
		vector<int> divi = getDivisor(i);
		for (int j = 0; j < divi.size(); j++){
			int s = i + divi[i];
			if (s <= m){
				if (step[s-n] > step[i-n] + 1){
					step[s-n] = step[i-n] + 1;
				}
			}
		}
	}
	
	return (step[m-n] != m) ? step[m-n] : -1;
}

int main(){
	int n = 0;
	int m = 0;
	while (cin >> n >> m){
		cout << getSteps(n, m) << endl;
	}
	return 0;
}