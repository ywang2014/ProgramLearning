/**
* String 类：
    综合利用学习的知识：
        默认构造函数、转换函数、拷贝构造函数
        友元函数、重载运算符函数
        重载输入/输出函数
        静态成员(函数)
*/

#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>

class MyString
{
private:
    char *str;
    int len;
    static int nums;
    static const int CINLIMIT = 80;

public:
    MyString();
    MyString(const char* ptr);
    MyString(const MyString& str);
    ~MyString();

    int length() const
    {
        return len;
    }

    MyString& stringLower();
    MyString& stringUpper();
    int numsOfCharInStr(const char ch) const;

    MyString& operator=(const char* ptr);
    MyString& operator=(const MyString& str);
    //MyString& operator+(const MyString& str) const;
    MyString operator+(const MyString& str) const;

    char operator[](int i);
    const char& operator[](int i) const;

    friend bool operator==(const MyString& str1, const MyString& str2);
    friend bool operator<(const MyString& str1, const MyString& str2);
    friend bool operator>(const MyString& str1, const MyString& str2);

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
    //friend char* operator=(char *ptr, const MyString& str);

    static int howMany()
    {
        return nums;
    }
};

#endif // _MYSTRING_H
