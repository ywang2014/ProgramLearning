/**
    C++程序设计语言--Stroustrup

    简单计算器，理解语法解析原理
    此版本处理非常粗燥，只能按照设计模式，标准输入才行
    错误处理能力很差

    输入：必须使用空格，结束 ;

    0.2 改进输入，可以从命令行读取输入
*/

#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <sstream>  // istringstream

using namespace std;

/*
    全局变量
*/
enum TokenValue
{
    NAME, NUMBER, END, PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
    PRINT = ';', ASSIGN = '=', LP = '(', RP = ')',
};
TokenValue curr_tok = PRINT;

double number_value;
string string_value;
// 符号表
map<string, double>table;


// 函数声明
double expr(bool);
double term(bool);
double prim(bool);
double error(const string&);
TokenValue get_token();


/*
    expr() 处理加法和减法
    bool 参数，指明函数是否需要调用get_token()函数，读取单词
    循环处理连加连减情况
*/
double expr(bool get)
{
    double left = term(get);
    for (; ; ) // 无限循环，根据输入自动结束
    {
        switch (curr_tok)
        {
        case PLUS:
            left += term(true);
            break;
        case MINUS:
            left -= term(true);
            break;
        default:
            return left;
        }
    }
}

/*
    term() 处理乘法、除法
*/
double term(bool get)
{
    double left = prim(get);
    for (; ; )
    {
        switch (curr_tok)
        {
        case MUL:
            left *= prim(true);
            break;
        case DIV:
            if (double div_num = prim(true))
            {
                left /= div_num;
                break;
            }
            else
            {
                return error("divide by 0");
            }
        default:
            return left;
        }
    }
}

/*
    处理初等项
*/
double prim(bool get)
{
    if (get)
    {
        get_token();
    }
    switch (curr_tok)
    {
    case NUMBER:    // 定义了变量，必须用花括号括起来，否则编译错误 error:   crosses initialization of 'double value_n'|
        {
            double value_n = number_value;
            get_token();
            return value_n;
        }

    case NAME:
        {
            double& value = table[string_value];    // &?
            if (get_token() == ASSIGN)
            {
                value = expr(true);     // 可能被修改，所以用引用
            }
            return value;
        }

    case MINUS:
        return -prim(true);

    case LP:
        {
            double e = expr(true);
            if (curr_tok != RP)
            {
                return error(") expected");
            }
            get_token();    // 消掉 ')'
            return e;
        }

    default:
        return error("primary expected");
    }
}


/*
    get_token 输入处理函数
*/
TokenValue get_token()
{
    char ch = 0;
    cin >> ch;

    switch (ch)
    {
    case 0:
        return curr_tok = END;  // 读入失败

    case ';':   // 同一类的处理方法一样，所以重叠
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
        return curr_tok = TokenValue(ch);

    case '0': case '1': case '2': case '3': case '4': case '5': case '6':
    case '7': case '8': case '9': case '.':     // 小数点，都是数字一类，统一处理
        cin.putback(ch);    // 回退一步，插入到输入流中
        cin >> number_value;
        return curr_tok = NUMBER;

    default:
        if (isalpha(ch))
        {
            cin.putback(ch);
            cin >> string_value;
            return curr_tok = NAME;
        }
        else
        {
            error("bad token");
            return curr_tok = PRINT;
        }
    }
}

/*
    错误处理
*/
int no_errors;   // 记录错误数量
double error(const string& str)
{
    no_errors++;

    cerr << "error: " << str << endl;
    return 1;
}

/*
    主程序，也叫驱动程序
*/
istream* input; // 指向输入流

int main(int argc, char* argv[])
{
    switch (argc)
    {
    case 1:
        input = &cin;   // 指向标准输入流
        break;

    case 2:
        input = new istringstream(argv[1]);
		break;

    default:
        error("too many arguments");
        return 1;
    }

    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    while (*input)
    {
        get_token();
        if (curr_tok == END)
        {
            break;
        }

        if (curr_tok == PRINT)
        {
            continue;
        }

        cout << expr(false) << endl;

        /* 等价
        if (curr_tok != PRINT)
        {
            cout << expr(false) << endl;
        }
        */
    }

    if (input != &cin)
    {
        delete input;   // 与 new 对应
    }

    return no_errors;
}
