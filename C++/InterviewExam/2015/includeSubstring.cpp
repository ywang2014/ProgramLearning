/*
* 笔试题目
*
 	子串包含问题：
		输入字符串a，可能包含汉字(双字节，高字节第一位为 1)
		输入字符串b，可能含有汉字
		
		规则：判断b中字符是否都在a中出现了，且遇到重复字符时，a出现至少相同的次数才行。
		
		输出：如果都出现了，则输出1，否则输出0(打印)
*/


#include <iostream>
#include <string>

using namespace std;

int isSubstr(string str_a, string str_b);
int hashArray[1000] = {0};    // 假设不超过一千种字符！

int main()
{
    string str_a;
    string str_b;

    cin >> str_a;
    cin >> str_b;

    cout << isSubstr(str_a, str_b) << endl;

    return 0;
}

int isSubstr(string str_a, string str_b)
{
    wchar_t ch;
    int flag = 1;

    for (unsigned int i = 0; i < str_a.size(); i++)
    {
        ch = str_a[i];
        int index = ch - 'A';
        cout << index << endl;
        hashArray[index]++;
    }

    for (unsigned int i = 0; i < str_b.size(); i++)
    {
        ch = str_b[i];
        int index = ch - 'A';
        cout << index << endl;
        if (hashArray[index] < 1)
        {
            flag = 0;
        }
        else
        {
            hashArray[index]--;
        }
    }

    return flag;
}
