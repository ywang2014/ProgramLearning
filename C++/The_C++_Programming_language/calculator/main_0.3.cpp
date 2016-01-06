/**
    C++程序设计语言--Stroustrup

    简单计算器，理解语法解析原理
    此版本处理非常粗燥，只能按照设计模式，标准输入才行
    错误处理能力很差

    输入：必须使用空格，结束 ;

    0.3 进一步优化输入，使得更加灵活
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
/*
输入值流，不能使用const
double expr(bool, const istream&);
double term(bool, const istream&);
double prim(bool, const istream&);
*/
double expr(bool, istream&);
double term(bool, istream&);
double prim(bool, istream&);

double error(const string&);
TokenValue get_token(istream&);
void manage(istream& input);


/*
    expr() 处理加法和减法
    bool 参数，指明函数是否需要调用get_token()函数，读取单词
    循环处理连加连减情况
*/
double expr(bool get, istream& input)
{
    double left = term(get, input);
    for (; ; ) // 无限循环，根据输入自动结束
    {
        switch (curr_tok)
        {
        case PLUS:
            left += term(true, input);
            break;
        case MINUS:
            left -= term(true, input);
            break;
        default:
            return left;
        }
    }
}

/*
    term() 处理乘法、除法
*/
double term(bool get, istream& input)
{
    double left = prim(get, input);
    for (; ; )
    {
        switch (curr_tok)
        {
        case MUL:
            left *= prim(true, input);
            break;
        case DIV:
            if (double div_num = prim(true, input))
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
double prim(bool get, istream& input)
{
    if (get)
    {
        get_token(input);
    }
    switch (curr_tok)
    {
    case NUMBER:    // 定义了变量，必须用花括号括起来，否则编译错误 error:   crosses initialization of 'double value_n'|
        {
            double value_n = number_value;
            get_token(input);
            return value_n;
        }

    case NAME:
        {
            double& value = table[string_value];    // &?
            if (get_token(input) == ASSIGN)
            {
                value = expr(true, input);     // 可能被修改，所以用引用
            }
            return value;
        }

    case MINUS:
        return -prim(true, input);

    case LP:
        {
            double e = expr(true, input);
            if (curr_tok != RP)
            {
                return error(") expected");
            }
            get_token(input);    // 消掉 ')'
            return e;
        }

    default:
        return error("primary expected");
    }
}


/*
    get_token 输入处理函数
*/
TokenValue get_token(istream& input)    // 为什么不能使用 const
{
    char ch = 0;
    input>>ch;

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
        input.putback(ch);    // 回退一步，插入到输入流中
        input >> number_value;
        return curr_tok = NUMBER;

    default:
        if (isalpha(ch))
        {
            input.putback(ch);
            input >> string_value;
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
    主体函数--manage()

    进一步优化，直接重定向到标注输入流，都使用new，实现统一
*/

void manage(istream& input)
{
    while (input)
    {
        get_token(input);
        if (curr_tok == END)
        {
            break;
        }

        if (curr_tok == PRINT)
        {
            continue;
        }

        cout << expr(false, input) << endl;

        /* 等价
        if (curr_tok != PRINT)
        {
            cout << expr(false) << endl;
        }
        */
    }

    /* 函数外处理更好
    if (input != &cin)
    {
        delete input;   // 与 new 对应
    }
    */
}


/*
    主程序，也叫驱动程序
*/

int main(int argc, char* argv[])
{
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    switch (argc)
    {
    case 1:
        //input = &cin;   // 指向标准输入流
        manage(cin);
        break;

    case 2:
        {   // 必须使用{} 定义新变量
            istream* input = new istringstream(argv[1]);
            manage(*input);

            delete input;   // new 对应，函数里面处理不好
            break;
        }

    default:
        error("too many arguments");
        return 1;
    }

    return no_errors;
}
