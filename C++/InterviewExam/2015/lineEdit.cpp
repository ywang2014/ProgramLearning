/*******************************************************************************************
*
* 360面试题
* 行编辑器：
    输入：第一行 整数n：代表有n行输入数据需要处理
            后面n行字符串！
        字符串小于100，每个字符一定是('a'~'z','A'~'Z', '*', '!', '(', ')', '+', '@', '#')中的一个
    输出：n行：
        规则：遇到'#'，则删除其前面一个字符；遇到'@',则删除其前面的一整行。

    test:
    3
    whli##ilr#e(s#*s)
    outcha@putchar(*s=#++)
    returnWA##A!!##C

    while(*s)
    putchar(*s++)
    returnAC
*********************************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int n = 0;
    string str_input;
    char output[100];   // 使用 string 不行？？？？

    cin >> n;

    while (n--)
    {
        cin >> str_input;

        int j = 0;
        for (unsigned int i = 0; i < str_input.size(); i++)
        {
            if (str_input[i] == '#')
            {
                j--;
            }
            else if (str_input[i] == '@')
            {
                j = 0;
            }
            else
            {
                if (j < 0)
                {
                    j = 0;
                }
                output[j++] = str_input[i];
            }
        }
        output[j] = '\0';

        cout << output << endl;
    }
    return 0;
}

