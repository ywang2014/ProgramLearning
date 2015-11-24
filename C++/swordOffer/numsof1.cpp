/*
	输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
	编程之美：三种思路解法
		1.直接对n%2==1 判断，再除2
		2.同样思路，用位运算 n&1 >>
		3. n&=(n-1)
*/

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while (n != 0)
             {
             count++;
             n &= (n-1);
         }
         return count;
     }
};