/**
THU2014 1-2 Company
描述
　　公司有n个员工，编号1 ~ n。员工数量众多，需要你为他们编写一个管理系统。

　　员工上班时都要登录管理系统登记一个code，离开要从管理系统上注销，员工也可以随时更新自己的code。到了下班时间，所有员工都会自动注销。公司管理人员随时都可能想要知道有多少员工上班，以及任一员工登记的code。

输入
　　第一行两个整数n、m。接下来m行，每行都是以下内容之一：

I	a	c	//Log In：员工a登录，code为c。若a已登录，则将code更新为c
O	a		//Log Out：编号为a的员工注销。若a未登录，则注销无效
C			//Close：到下班时间，所有员工注销
N			//Number：询问有多少员工正在上班
Q	a		//Query：询问员工a的code（若未登录或已注销，视为-1）
输出
　　一个整数，是所有询问（N、Q）的答案之和（int表示，自动溢出，不用管溢出部分）

输入样例

10	8
I	1	2
I	1	4
Q	1
C
I	2	4
O	2
Q	2
N
输出样例

3
//“Q 1”答案是4，“Q 2”答案是-1，“N”答案是0，所有答案之和为3
限制
　　n <= 10,000,000

　　m <= 1,000,000

　　1<=a<=n

　　code为[0, 2^31)的整数

　　空间限制：256 MB

　　时间限制：2 sec

提示
一级提示

　　测试数据中，每种操作都可能频繁出现，或很少出现。因此，你的算法需要应对所有可能的情况。
	
*/

#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>

using namespace std;

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	
	// 员工标号数组
	int *member = new int[n+1];
	//memset(member, -1, sizeof(member));	//	memset刚刚好可以初始化 0，-1，其他的值不行。
	memset(member, -1, (n+1) * sizeof(int));
	
	char operator_flag[2];	// 输入操作标记，避免%c不能解决空格，回车等标记字符
	char flag;
	
	int number = 0, code = 0;
	
	member[0] = 0;	// 专门用于统计登录的员工
	int result = 0;		// 最终结果
	while (m > 0)
	{
		scanf("%s", operator_flag);
		if (strcmp(operator_flag,"I")==0)
		{
			flag = 'I';
		}
		else if (strcmp(operator_flag,"O")==0)
		{
			flag = 'O';
		}
		else if (strcmp(operator_flag,"C")==0)
		{
			flag = 'C';
		}
		else if (strcmp(operator_flag,"N")==0)
		{
			flag = 'N';
		}
		else if (strcmp(operator_flag,"Q")==0)
		{
			flag = 'Q';
		}
		else	// 输入异常情况
		{
			return 0;
		}
		
		switch (flag)
		{
			case 'I':
				scanf("%d%d", &number, &code);
				if (member[number] == -1)	// 未登录，登录
				{
					member[0]++;
				}
				member[number] = code;
				break;
				
			case 'O':
				scanf("%d", &number);
				if (member[number] != -1)	// 在线，注销
				{
					member[0]--;
					member[number] = -1;
				}
				break;
				
			case 'C':
				//memset(member, -1, sizeof(member));	// 对了50%
				memset(member, -1, (n+1) * sizeof(int));
				member[0] = 0;
				break;
				
			case 'N':
				result += member[0];
				break;
				
			case 'Q':
				scanf("%d", &number);
				result += member[number];
				break;
				
			default :
				break;
				
		}
		
		m--;
	}
	
	printf("%d\n", result);
	
	return 0;
}