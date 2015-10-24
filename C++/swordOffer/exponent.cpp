/*
* 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。 
* 分析：减少时间复杂度--分而治之策略
* 注意：幂次可能为负！
*/

class Solution {
public:
    double Power(double base, int exponent) {
		if (exponent == 0)
		{
			return 1.0;
		}
        else if (exponent < 0)
		{
            exponent = -exponent;
			return 1 / positive_power(base, exponent);
        }
		else
		{
			return positive_power(base, exponnent);
		}
    }
	
	double positive_power(double base, int exponent)
	{
		if (exponent == 1)
		{
			return base;
		}
		else if (exponent == 2)
		{
			return base * base;
		}
		else
		{
			int half = exponent >> 1;
			return positive_power(base, half) * positive_power(base, exponent - half);
		}
	}
};

class Solution {
public:
    double Power(double base, int exponent) {
        int p = abs(exponent);
      double r = 1.0;
        while(p){
            if(p & 1) r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1/ r : r;
    }
};