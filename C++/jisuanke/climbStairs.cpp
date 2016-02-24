/**
	假设你现在正在爬楼梯，楼梯有n级。每次你只能爬1级或者2级，那么你有多少种方法爬到楼梯的顶部？

	格式：

   第一行输入一个数n(n<=50)，代表楼梯的级数。

   接下来一行输出你的方法总数
   
   例如：
	输入：5
	输出：8
*/

#include <iostream>

int main()
{
	int n = 0;
	while (std::cin >> n)
	{
		if (n == 1)
		{
			std::cout << 1 << std::endl;
			break;
		}
		
		int a = 1;
		int b = 2;
		while (n > 2)
		{
			b += a;
			a = b - a;
			n--;
		}
		std::cout << b << std::endl;
	}
	
	return 0;
}