/**
*   String 类方法定义的实现
*
*/

#include <cstring>
#include "mystring.h"

int MyString::nums = 0;

MyString::MyString()
{
    len = 0;
    str = new char[1];  // 必须使用 new[]，与析构函数配套，否则析构函数会发生错误
    str[0] = '\0';
    nums++;
}

MyString::MyString(const char* ptr)
{
    len = std::strlen(ptr);
    str = new char[len + 1];
    std::strcpy(str, ptr);
    nums++;
}

MyString::MyString(const MyString& str)
{
    len = str.len;  // 成员函数可以访问私有成员？？？
    this->str = new char[len + 1];
    std::strcpy(this->str, str.str);
    nums++;
}

MyString::~MyString()
{
    delete[] str;
    nums--;
}

MyString& MyString::stringLower()
{
    char* ptr = str;
    for (int i = 0; i <= len; i++)
    {
        if (*ptr >= 65 && *ptr <= 90)
        {
            *ptr += 32;
            //std::cout << *ptr;
        }
        ptr++;
    }
    //std::cout << std::endl;
    return *this;
}

MyString& MyString::stringUpper()
{
    char* ptr = str;
    for (int i = 0; i <= len; i++)
    {
        if (*ptr >= 97 && *ptr <= 122)
        {
            *ptr -= 32;
        }
        ptr++;
    }
    //std::cout << std::endl;
    return *this;
}

int MyString::numsOfCharInStr(const char ch) const
{
    int num = 0;
    char *ptr = str;
    for (int i = 0; i <= len; i++)
    {
        if (*ptr == ch)
        {
            num++;
        }
        ptr++;
    }
    return num;
}

MyString& MyString::operator=(const char* ptr)
{
    len = std::strlen(ptr);
    str = new char[len + 1];
    std::strcpy(str, ptr);
    return *this;
}

MyString& MyString::operator=(const MyString& str)
{
    if (this == &str)
    {
        return *this;
    }

    len = str.len;

    delete[] this->str;

    this->str = new char[len + 1];
    std::strcpy(this->str, str.str);
    return *this;
}

/*
MyString& MyString::operator+(const MyString& str) const
{
    MyString *temp = new MyString();
    temp->len = len + str.len;

    delete[] temp->str;

    temp->str = new char[temp->len + 1];

    std::strcpy(temp->str, this->str);
    std::strcat(temp->str, str.str);

    return *temp;
}
*/
MyString MyString::operator+(const MyString& str) const
{
    MyString temp;
    temp.len = len + str.len;

    delete[] temp.str;

    temp.str = new char[temp.len + 1];

    std::strcpy(temp.str, this->str);
    std::strcat(temp.str, str.str);

    return temp;
}


char MyString::operator[](int i)
{
    return str[i];
}

const char& MyString::operator[](int i) const
{
    return str[i];
}

/********************************* friend function ************************************/
bool operator==(const MyString& str1, const MyString& str2)
{
    return (std::strcmp(str1.str, str2.str) == 0);
}

bool operator<(const MyString& str1, const MyString& str2)
{
    return (std::strcmp(str1.str, str2.str) < 0);
}

bool operator>(const MyString& str1, const MyString& str2)
{
    return (std::strcmp(str1.str, str2.str) > 0);
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.str;

    return os;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
    char temp[MyString::CINLIMIT];
    is.get(temp, MyString::CINLIMIT);

    if (is)
    {
        str = temp;
    }
    while (is && is.get() != '\n')  // 将缓冲区多余的输出清空！
    {
        continue;
    }

    return is;
}

//friend char* operator=(char *ptr, const MyString& str);

