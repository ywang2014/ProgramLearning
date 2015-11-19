/**
    面向过程式的猜词游戏--hangman

    主要练习string类的方法：
        = + != 等都被重载的运算符
        find()
        string::npos
        友元函数 operator<<()/tolower()

    子程序编写--一个模块负责一个功能，命名准确

    改进版本----纯面向对象
        封装一个游戏类
        建立 has-a 包含关系

    @date 2015-11-19
    @author ywang
    @see 参考 C++ primer
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void manager();
void getWords(string *p);
int setGuessNum();
void playGame(int &guesses);
bool guessCharacter(string &bad, string &attempt, const string &target, int &guess);
void setAttempt(const char &ch, string &word, const string &target);
bool isExist(const string &bad, const string &attempt, const char &ch);
void show(const string &good, const string &bad, const string &target, const int &guess);
void showResult(const int &guess, const string &target);

static const int N = 275;
static string words[N];

int main()
{
    manager();

    return 0;
}

void manager()
{
    system("color 9e");
    system("cls");
    cout << "\n\n";
    string spaces = "        ";
    cout << spaces << spaces << "Hello boys and girls\n\n";

    getWords(words);

    cout << spaces << "你想玩猜单词游戏吗？<y/n>";
    char play = '\0';
    cin >> play;
    play = tolower(play);

    while (play == 'y')
    {
        int guesses = setGuessNum();

        playGame(guesses);

        cout << spaces << "你想继续玩猜单词游戏吗？<y/n>";
        cin >> play;
        play = tolower(play);

        system("cls");
        cout << "\n\n";
    }
}

void getWords(string *p)
{
    ifstream fin;
    fin.open("wordlist.txt");
    if (fin.is_open() == false)
    {
        cerr << "        Can't open file. Try it latter!\n";
        exit(1);
    }
    int i = 0;
    while (i < N && (fin >> p[i]))
    {
        i++;
    }

    fin.close();
}

int setGuessNum()
{
    int guess = 0;

    //cout << "Please choose the guessing numbers: d \n";
    cout << "        请选择猜测次数：d：默认值--6   或者重新设置\n";
    char choice = '\0';
    cout << "        ";
    cin >> choice;
    choice = tolower(choice);
    if (choice == 'd')
    {
        guess = 6;
    }
    else
    {
        cout << "        设置猜测次数：n--";
        cin >> guess;
    }

    return guess;
}

void playGame(int &guesses)
{
    srand((unsigned)time(0));
    string target = words[rand() % N];
    int len = target.length();
    string attempt(len, '-');
    string badchars;

    cout << "        猜测的单词---单词共有 " << len << " 字母\n";
    cout << "        每次猜测一个字母，你有 " << guesses << " 次猜测机会\n\n";

    //cout << "你的单词：" << attempt << endl;

    while (guesses > 0 && attempt != target)
    {
        if (! guessCharacter(badchars, attempt, target, guesses))
        {
            continue;
        }

        show(attempt, badchars, target, guesses);
    }

    showResult(guesses, target);
}

void showResult(const int &guess, const string &target)
{
    system("cls");
    cout << "\n\n\n\n";
    if (guess > 0)
    {
        cout << "        恭喜你全部猜对了！\n\n";
    }
    else
    {
        cout << "        有点遗憾，你的猜测次数已经用完了！\n\n";
        cout << "        正确答案是：" << target << endl;
    }
    cout << endl;
}

bool guessCharacter(string &bad, string &attempt, const string &target, int &guess)
{
    char letter;
    cout << "        猜一个字母：";
    cin >> letter;

    if (isExist(bad, attempt, letter))
    {
        return false;
    }

    unsigned int loc = target.find(letter);
    if (loc == string::npos)
    {
        cout << "        猜测错误，好好加油！\n";
        guess--;
        bad += letter;
    }
    else
    {
        setAttempt(letter, attempt, target);
    }

    return true;
}

void setAttempt(const char &ch, string &word, const string &target)
{
    unsigned int loc = target.find(ch);
    cout << "        恭喜你，猜对了！\n";

    while (loc != string::npos)
    {
        word[loc] = ch;
        loc = target.find(ch, loc+1);
    }
}

bool isExist(const string &bad, const string &attempt, const char &ch)
{
    if (bad.find(ch) != string::npos || attempt.find(ch) != string::npos)
    {
        cout << "        这个字母你已经猜测过了，请再猜其他的：\n";
        return true;
    }

    return false;
}

void show(const string &good, const string &bad, const string &target, const int &guess)
{
    string spaces = "        ";

    cout << spaces << "你猜对的字母：" << good << endl;
    if (good != target)
    {
        if (bad.length() > 0)
        {
            cout << spaces << "你猜错的字母表：" << bad << endl;
        }
        cout << spaces << "你还有 " << guess << " 次猜测机会！\n";
    }
    cout << endl;
}


