/**
    华为在线试题
	研发中心
    http://ilearning.hwclouds.com/exam/
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include<algorithm>

using namespace std;

int get_num_len(int num){
    if (num == 0){
        return 1;
    }
    int res = 0;
    while (num){
        res++;
        num /= 10;
    }
    return res;
}

int pow_n(int num, int n){
    if (num == 0){
        return 0;
    }

    int res = 1;
    for (int i = 0; i < n; i++){
        res *= num;
    }
    return res;
}

bool is_narcissus(int num){
    if (num == 0){
        return true;
    }
    int len = get_num_len(num);
    int num_copy = num;
    while (num_copy){
        int bit_num = num_copy % 10;
        num_copy /= 10;
        num -= pow_n(bit_num, len);
    }
    return num == 0;
}

int main()
{
    int s_num = 0;
    int e_num = 0;
    while (cin >> s_num >> e_num){
        int res = 0;
        for (int i = s_num; i <= e_num; i++){
            if (is_narcissus(i)){
                cout << i << endl;
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}

/**
    水仙花数升级版
    描述:
    水仙花数是指一个 n 位数 ( n≥3 )，它的每个位上的数字的 n 次幂之和等于它本身。（例如：1^3 + 5^3+ 3^3 = 153）
    给你A和B，求[A,B]区间内有多少个水仙花数

    运行时间限制:	无限制
    内存限制:	无限制
    输入:
    两个正整数，用空格隔开，保证数字都小于等于1000000。
    输出:
    一个数字，表示[A,B]区间内的水仙花数个数
    样例输入:
    100 1000
    样例输出:
    4
    答案提示:
    100~1000的水仙花数有：153，370，371，407
*/
