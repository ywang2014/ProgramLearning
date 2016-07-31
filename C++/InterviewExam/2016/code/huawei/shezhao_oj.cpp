/**
    华为在线试题
	社招
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

void get_h_m_s(string time, int &h, int &m, int &s){
    h = atoi(time.substr(0, 2).c_str());
    m = atoi(time.substr(3, 2).c_str());
    s = atoi(time.substr(6, 2).c_str());
}

int main()
{
    string a_time;
    string b_time;
    while (cin >> a_time >> b_time){
        int a_h = 0;
        int a_m = 0;
        int a_s = 0;
        get_h_m_s(a_time, a_h, a_m, a_s);
        int b_h = 0;
        int b_m = 0;
        int b_s = 0;
        get_h_m_s(b_time, b_h, b_m, b_s);
        int res_s = a_s + b_s;
        int res_m = a_m + b_m;
        int res_h = a_h + b_h;
        if (res_s >= 60){
            res_s -= 60;
            res_m++;
        }
        if (res_m >= 60){
            res_m -= 60;
            res_h++;
        }
        if (res_h >= 24){
            res_h -= 24;
        }
        if (res_h < 10){
            cout << "0" << res_h << ":";
        }
        else{
            cout << res_h << ":";
        }
        if (res_m < 10){
            cout << "0" << res_m << ":";
        }
        else{
            cout << res_m << ":";
        }
        if (res_s < 10){
            cout << "0" << res_s;
        }
        else{
            cout << res_s;
        }
    }
    return 0;
}

/**
    对数计数器
    描述:
    小明在使用一个计数器，计数范围0~999999，小明第一次看计数器的时候，其读数为一个对数（即正反读是一样的，如12321），当出现下一个对数的时候，小明停止了计数。
    输入小明看到的第一个对数，请输出计数数量（即第二个对数跟第一个对数的差值）。注意，计数器达到999999后，会重新从0开始。
    运行时间限制:	无限制
    内存限制:	无限制
    输入:
    输入一个整数0~999999
    输出:
    输出计数数量，非负整数
    样例输入:
    123321
    样例输出:
    1100 = 124421 - 123321
*/
int get_num_len(int num){
    if (num <= 0){
        return 1;
    }
    int res = 0;
    while (num){
        res++;
        num /= 10;
    }

    return res;
}


void counter(){
    int num = 0;
    while (cin >> num){
        if (num < 0 || num > 999999){
            break;
        }
        if (num == 9 || num == 99 || num == 999 || num == 9999 || num == 99999){
            cout << 2 << endl;
            return ;
        }
        else if (num == 999999){
            cout << 12 << endl;
            return ;
        }

        switch (get_num_len(num)){
        case 1:
            cout << 1 << endl;
            break;
        case 2:
            cout << 11 << endl;
            break;
        case 3:
            cout << 10 << endl;
            break;
        case 4:
            cout << 110 << endl;
            break;
        case 5:
            cout << 100 << endl;
            break;
        case 6:
            cout << 1100 << endl;
            break;
        default:
            break;
        }
    }
}


/**
    实现两个合法时间相加
    描述:
    给定两个合法的时间（格式固定：hh:mm:ss，时间合法，不用考虑其它情况），输入两个时间相加后的结果；注意，相加后的结果也必需是一个合法的时间；
    附合法时间定义：小时在[00-23]之间，分钟和秒分别是在[00-59]之间；
    运行时间限制:	无限制
    内存限制:	无限制
    输入:
    时分秒格式的时间字符串，如00:00:00
    输出:
    时分秒格式的时间字符串，如00:00:00

    样例输入:
    00:00:00 00:00:01
    样例输出:
    00:00:01
    答案提示:
    建议将时间转换为秒数计算
*/
void get_h_m_s(string time, int &h, int &m, int &s){
    h = atoi(time.substr(0, 2).c_str());
    m = atoi(time.substr(3, 2).c_str());
    s = atoi(time.substr(6, 2).c_str());
}

void time_add(){
    string a_time;
    string b_time;
    while (cin >> a_time >> b_time){
        int a_h = 0;
        int a_m = 0;
        int a_s = 0;
        get_h_m_s(a_time, a_h, a_m, a_s);
        int b_h = 0;
        int b_m = 0;
        int b_s = 0;
        get_h_m_s(b_time, b_h, b_m, b_s);
        int res_s = a_s + b_s;
        int res_m = a_m + b_m;
        int res_h = a_h + b_h;
        if (res_s >= 60){
            res_s -= 60;
            res_m++;
        }
        if (res_m >= 60){
            res_m -= 60;
            res_h++;
        }
        if (res_h >= 24){
            res_h -= 24;
        }
        if (res_h < 10){
            cout << "0" << res_h << ":";
        }
        else{
            cout << res_h << ":";
        }
        if (res_m < 10){
            cout << "0" << res_m << ":";
        }
        else{
            cout << res_m << ":";
        }
        if (res_s < 10){
            cout << "0" << res_s;
        }
        else{
            cout << res_s;
        }
    }
}
