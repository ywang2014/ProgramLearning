/**
*   test MyString class
*
*/


#include <iostream>
#include "MyString.h"

int main()
{
    using namespace std;

    cout << "Hello boys, let us begin!\n";

    MyString str1;  // Constructor without argument

    MyString str2("Hello, girls!"); // MyString(const char*)

    cout << MyString::howMany() << endl;
    cout << "String \"" << str1 << "\" lenght is " << str1.length() << endl;
    cout << "String \"" << str2 << "\" lenght is " << str2.length() << endl;
    cout << "index: " << str2[0] << " " << str2[1] << " " << str2[2] << " " << str2[3] << endl;

    MyString str3 = str2;
    str1 = str3;

    cout << MyString::howMany() << endl;
    cout << str1 << endl;
    cout << str2.stringUpper() << endl;
    cout << (str2 < str1) << endl;
    cout << str2.stringLower() << endl;
    cout << (str2 < str1) << endl;
    cout << str3 << endl;
    cout << (str3 < str1) << endl;
    cout << (str3 == str1) << endl;
    cout << (str3 > str1) << endl;

    cout << "/************************ short sayings **********************************/" << endl;
    MyString sayings[10];
    int shortsaying = 0;
    int firstsaying = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ": ";
        cin >> sayings[i];

        if (sayings[i].length() < sayings[shortsaying].length())
        {
            shortsaying = i;
        }
        if (sayings[i] < sayings[firstsaying])
        {
            firstsaying = i;
        }
    }

    cout << "\nShortest saying is \"" << sayings[shortsaying] << "\"" << endl;
    cout << "\nFirst saying is \"" << sayings[firstsaying] << "\"" << endl;

    cout << "/************************ short sayings **********************************/" << endl;

    cout << endl << endl;

    MyString s1(" and I am a C++ fans.");
    MyString s2("Please enter your name: ");
    MyString s3;
    cout << s2;
    cin >> s3;
    s2 = MyString("My name is ") + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringUpper();
    cout << "The string \"" << s2 << "\" contains " << s2.numsOfCharInStr('A') << " 'A' characters in it.\n";

    return 0;
}
