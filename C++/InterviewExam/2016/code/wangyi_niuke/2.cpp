/**
	小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
	例如：半径的平方如果为25
		优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。 
		输入描述:
			输入为一个整数，即为圆半径的平方,范围在32位int范围内。
		输出描述:
			输出为一个整数，即为优雅的点的个数
			
		输入例子:
			25
		输出例子:
			12
*/

#include <iostream>
#include <cmath>

using namespace std;

bool solution(int a, int b){
    int dif = a - b * b;
    int c = (int) sqrt(dif);
    if (c * c == dif){
        return true;
    }
    return false;
}

int main(){
    int r2 = 0;
    while (cin >> r2){
        int count = 0;
        int r = (int) sqrt(r2);
        // if (r * r == r2){
            0比较特殊
            // count += 4;
        // }
        // for (int i = 1; i < r; i++){
            // if (isOk(r2, i)){
                // count += 4;
            // }
        // }
		for (int i = 1; i <= r; i++){
			if (solution(r2, i)){
				count += 4;
			}
		}
        cout << count << endl;
    }
    return 0;
}