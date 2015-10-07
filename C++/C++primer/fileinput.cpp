/*
    文件输入的解析方法
    字符串读取输入，按照需要解析！
        特殊字符结束输入
        读到文件结尾
        安全控制，防止输入错误！
*/

#include <iostream>
#include <limits>       // 使用numeric_limits
#ifndef EOF
#define EOF (-1)
#endif // EOF

int main()
{
    using namespace std;
    int ch_count = 0;   // counter
    char ch;            // the input character

    cout << "Hello boys!" << endl;

    cout << "\'\\n\' is the end." << endl;
    cout << "Please enter some characters :" << endl;
    cin.get(ch);    // read a character
    ch_count = 0;
    // Method 1: break by '\n'
    while (ch != '\n')
    {
        // read a line and show
        cout << ch;
        ch_count++;
        cin.get(ch);
    }
    cout << "\nThe end character is " << ch << endl;
    cout << "The total characters are " << ch_count << endl;
    cout << "********************************************************\n\n";

    //rewind(STDIN_FILENO);   // clear the input buffer.

    // numeric_limits<streamsize>::max() 返回输入缓冲的大小
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');    // ignore 函数来清除输入流中的数据
    // It does not need now, because any input is end of '\n' unless a file, so there is nothing in the buffer.


    cout << "'#@' is the end." << endl;
    cout << "Continue to enter some characters :" << endl;
    cin.get(ch);    // read a character
    ch_count = 0;
    // Method 2: break by "#@"
    while (true)
    {
        // read characters and show
        if (ch == '#')
        {
            char end_flag;
            cin.get(end_flag);
            if (end_flag == '@')
            {
                break;
            }
            else
            {
                cout << ch << end_flag;
                ch_count++;
                cin.get(ch);
            }
        }
        else
        {
            cout << ch;
            ch_count++;
            cin.get(ch);
        }
    }
    cout << "\nThe end character is " << ch << '@' << endl;
    cout << "The total characters are " << ch_count << endl;
    cout << "********************************************************\n\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "End Of File is the end." << endl;
    cout << "Continue to enter some characters :" << endl;
    cin.get(ch);    // read a character
    ch_count = 0;
    // Method 3: break by end of file
    while (! cin.eof()) // cin.eof() cin.fail() when end of the file they return True.
    {
        // read a file and show
        cout << ch;
        ch_count++;
        cin.get(ch);
    }
    cout << "\nThe end character is " << ch << endl;
    cout << "The total characters are " << ch_count << endl;
    cout << "********************************************************\n\n";

    cin.clear();    // cancel the eof bit flag


    cout << "Reading failed is the end." << endl;
    cout << "Continue to enter some characters :" << endl;

    ch_count = 0;
    // Method 4: break by reading failed
    while (cin.get(ch)) // cin will become a boolean when program needs. cin.get() return cin
    {
        // It is really a great way!

        // show
        cout << ch;
        ch_count++;
    }
    cout << "\nThe end character is " << ch << endl;
    cout << "The total characters are " << ch_count << endl;
    cout << "********************************************************\n\n";

    cin.clear();    // cancel the eof bit flag


    // the same as C language getchar() and putchar()
    cout << "EOF is the end." << endl;
    cout << "Continue to enter some characters :" << endl;

    ch_count = 0;
    int cha = cin.get();    // Now, in this way, cin.get() will return a character instead of a cin object.
    // Method 5: break by end of file
    while (cha != EOF) // cin will become a boolean when program needs. cin.get() return cin
    {
        // read a character and show
        cout.put(char(cha));    // putchar()
        ch_count++;
        cha = cin.get();        // getchar()
    }
    cout << "\nThe end character is " << cha << endl;
    cout << "The total characters are " << ch_count << endl;
    cout << "********************************************************\n\n";

    cin.clear();    // cancel the eof bit flag

    return 0;
}
