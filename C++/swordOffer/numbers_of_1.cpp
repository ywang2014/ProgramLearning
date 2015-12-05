/*
问题描述：
	给定一个十进制整数N,求出从1到N的所有整数中出现”1”的个数。 
      例如：N=2，1,2出现了1个“1”。
            N=12，1,2,3,4,5,6,7,8,9,10,11,12。出现了5个“1”。
*/

#include <iostream>

using namespace std;

int calculate_1(int n);

int main()
{
    int n = 0;

    while (cin >> n)
    {
        cout << calculate_1(n) << endl;
    }
    return 0;
}

int calculate_1_nums(int n)
{
    int high_bit = 0;
    int bit = 0;
    int low_bit = 0;
    int dec = 1;

    int nums = 0;

    while (n/dec > 0)
    {
        bit = (n / dec) % 10;
        high_bit = n / (dec * 10);
        low_bit = n - (n / dec) * dec;  // 减法解决了只有个位的问题

        switch (bit)
        {
        case 1:
            nums += high_bit * dec  + 1  + low_bit;
            break;
        case 0:
            nums += high_bit * dec;
            break;
        default :
            nums += (high_bit + 1) * dec;
            break;
        }

        dec *= 10;
    }

    return nums;
}


/*
题目描述

NowCoder总是力争上游，凡事都要拿第一，所以他对“1”这个数情有独钟。爱屋及乌，他也很喜欢包含1的数，例如10、11、12……。你能帮他统计一下有多少个包含1的正整数吗？ 

目标：求的是包含数字1的整数个数！
*/

/*
	计算最大n位数包含1的整数个数
		0-9 1位 1
		99  2位 19
*/
int one_nums_by_bit(int n)
{
    int tmp = n;
	int bits = 0;
	while (tmp > 0)
	{
		bits++;
		tmp /= 10;
	}
	
	// 0、1等特殊情况也成立！
	int count = 1;
	int num = 1;
    while(bits)
    {
        count *= 10;
        num *= 9;
        bits--;
    }
	
	return count-num;
}

// 递归实现


int calculate_1_numbers(int n)
{
    int nums = 0;
    int dec = 1;
    int bit = 0;

    int onesPerI = 0;
    int countN = 0;

    while (n > 0)
    {
        bit = n % 10;

        switch (bit)
        {
        case 0:
            break;
        case 1:
            nums = onesPerI + countN + 1;
            break;
        default:
            nums += (bit - 1) * onesPerI + dec;
            break;
        }

        countN += bit * dec;	// 将n从低位开始复原
        onesPerI = onesPerI * 9 + dec;	// ? 1、19、271 == one_nums_by_bit返回值
        dec *= 10;
        n /= 10;
    }

    return nums;
}
   
   