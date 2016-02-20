/**
	写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串
	oxa  <--> 10
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    while (cin >> str)
    {
        long long num = 0;
        int value = 0;
    
        for (int i =  2; i < str.size(); i++)
        {
            if (str[i] >= 'a')
            {
                value = str[i] - 'a' + 10;
            }
            else if (str[i] >= 'A')
            {
                value = str[i] - 'A' + 10;
            }
            else
            {
                value = str[i] - '0';
            }

            num = num * 16 + value;
        }

        cout << num << endl;
    }


    return 0;
}
