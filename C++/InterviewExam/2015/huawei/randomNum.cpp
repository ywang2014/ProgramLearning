/**

	明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复
的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
请你协助明明完成“去重”与“排序”的工作。
 
Input Param 
     n               输入随机数的个数     
 inputArray      n个随机整数组成的数组 
     
Return Value
     OutputArray    输出处理后的随机整数
 

注：测试用例保证输入参数的正确性，答题者无需验证。
*/

#include <iostream>

using namespace std;

int main()
{
    static int arr[1001];	// 桶排序原理
    for (int i = 0; i < 1001; i++)
    {
        arr[i] = 0;		// 初始化
    }

    int n = 0;
    cin >> n;

    int value = 0;
    while (n != 0)
    {
        cin >> value;
        arr[value] = 1;		// 只标记，不计数
        n--;
    }

    for (int i = 0; i < 1001; i++)
    {
        if (arr[i] == 1)	// 按照标记输出
        {
            cout << i << endl;
        }
    }

    return 0;
}

/*************************************
// 提交的代码

#include <iostream>
 
using namespace std;
 
int main()
{
    static int arr[1001];
 
 
    int n = 0;
    while (cin >> n)
    {
        for (int i = 0; i < 1001; i++)
        {
            arr[i] = 0;
        }
 
        int value = 0;
        while (n != 0)
        {
            cin >> value;
            arr[value] = 1;
            n--;
        }
 
        for (int i = 0; i < 1001; i++)
        {
            if (arr[i] == 1)
            {
                cout << i << endl;
            }
        }
    }
 
    return 0;
}

************************************************/
