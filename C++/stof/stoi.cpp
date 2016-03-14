/**
	stof算法实现
	
	字符串转化为浮点数，还没有想好。
	
	简单实现了一个字符串转化为整数的算法
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int str2i(string str)
{
    //if (str)
    //{
    //    cout << "Invalid argus.\n";
    //    return 0;
    //}

    bool isPositive = true;
    bool zerobit = true;
    if (str[0] == '-')
    {
        isPositive = false;
        zerobit = false;
    }
    else if (str[0] == '+')
    {
        zerobit = false;
    }

    int result  = 0;
    unsigned int index = (zerobit ? 0 : (unsigned int)1);
    for (unsigned int i = index; i < str.size(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            result = result * 10 + str[i] - '0';
        }
        else   // 不识别非数字部分
        {
            break;
        }
    }

    return isPositive ? result : -result;
}

int main()
{
    vector<string> str = {"000", "123", "-123", "abc", "12a", ""};
    for (unsigned int i = 0; i < str.size(); i++)
    {
        cout << str2i(str[i]) << endl;
    }

    string strNull;
    cout << str2i(strNull) << endl;
    return 0;
}
